#include "../include/PEData.hpp"

using std::vector;
using std::string;
using std::size_t;


//! ---------- CONSTRUCTORS ----------

PEData::PEData ()
{

}

PEData::PEData (const string& path)
{
    LoadPEFile (path);
}

PEData::PEData (const char* path)
{
    LoadPEFile (path);
}

PEData::PEData (const char* data, const size_t size)
{
    LoadPEData (data, size);
}


//! ---------- METHODS ----------

bool PEData::LoadPEFile (const string& path)
{
    // ---------- LOAD FILE ----------
    data.LoadBinaryFile (&path[0]);

    // ---------- GET DATA ----------
    return ExtractPEComponents();
}

bool PEData::LoadPEFile (const char* path)
{
    // ---------- LOAD FILE ----------
    data.LoadBinaryFile (path);

    // ---------- GET DATA ----------
    return ExtractPEComponents();
}


//--------------------------------------------------
//--------------------------------------------------


bool PEData::LoadPEData (const char* data, const size_t size)
{
    // ---------- LOAD DATA ----------
    this->data.SetData(data,size);

    // ---------- GET DATA ----------
    return ExtractPEComponents();
}


//--------------------------------------------------
//--------------------------------------------------


bool PEData::ExtractPEComponents ()
{
    // ---------- CHECK DATA ----------
    if (data.IsEmpty())
        return false;

    // ---------- DOS HEADER ----------
    DOSHeader       = *reinterpret_cast<IMAGE_DOS_HEADER*>(data.GetBeginPointer());

    if (DOSHeader.e_magic != IMAGE_DOS_SIGNATURE)
        return false;

    // ---------- DOS PROGRAM ----------
    size_t dosProgramSize = DOSHeader.e_lfanew     - sizeof(IMAGE_DOS_HEADER);
    char* dosProgramBegin = data.GetBeginPointer() + sizeof(IMAGE_DOS_HEADER);

    DOSProgram.SetData( dosProgramBegin , dosProgramSize );

    // ---------- PE SIGNATURE ----------
    Signature       = *reinterpret_cast<ULONG*>(data.GetBeginPointer() + DOSHeader.e_lfanew);

    if (Signature != IMAGE_NT_SIGNATURE)
        return false;

    // ---------- PE HEADERS ----------
    FileHeader      = *reinterpret_cast<IMAGE_FILE_HEADER*>      (data.GetBeginPointer() + DOSHeader.e_lfanew + sizeof(Signature));
    OptionalHeader  = *reinterpret_cast<IMAGE_OPTIONAL_HEADER32*>(data.GetBeginPointer() + DOSHeader.e_lfanew + sizeof(Signature) + sizeof(FileHeader));

    IMAGE_SECTION_HEADER*   sectionHeaders  =   reinterpret_cast<IMAGE_SECTION_HEADER*>(data.GetBeginPointer() + DOSHeader.e_lfanew + sizeof(IMAGE_NT_HEADERS32));

    for (int i=0;  i<FileHeader.NumberOfSections;  i++)
    {
        sections.emplace_back(&sectionHeaders[i], data.GetBeginPointer()+sectionHeaders[i].PointerToRawData);
    }

    return true;
}
