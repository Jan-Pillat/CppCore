#ifndef _HPP_PEData_
#define _HPP_PEData_

#include <windows.h>
#include <vector>
#include <string>
#include "BinaryData.hpp"
#include "FileData.hpp"

using std::vector;
using std::string;
using std::size_t;

// ======================== PE DECLARATIONS ========================

struct PESection
{
    IMAGE_SECTION_HEADER    header;
    BinaryData              rawData;

    PESection (const IMAGE_SECTION_HEADER* gotHeader, const char* gotRawData)
    {
        header = *gotHeader;
        rawData.SetData(gotRawData, header.SizeOfRawData);
    }

    PESection ()
    {

    }
};

// ======================== PE CLASS ========================

//    IMAGE_NT_HEADERS32      PEHeaders;    <--- Without this references are shorter.
class PEData
{
public:
// ---------- CONSTRUCTORS ----------
    PEData ();
    PEData (const string&   path);
    PEData (const char*     path);
    PEData (const char*     data, const size_t size);

// ---------- BINARY DATA FROM FILE ----------
    FileData data;

// ---------- EXTRACTED DATA ----------
    IMAGE_DOS_HEADER        DOSHeader;
    BinaryData              DOSProgram;
    ULONG                   Signature;
    IMAGE_FILE_HEADER       FileHeader;
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;

    vector   <PESection>    sections;

// ---------- METHODS ----------
    bool LoadPEFile (const string&  path);
    bool LoadPEFile (const char*    path);
    bool LoadPEData (const char*    data, const size_t  size);
    bool ExtractPEComponents ();
};

#endif
