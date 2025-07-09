#ifndef _HPP_FileData_
#define _HPP_FileData_

#include <cstddef>
#include <cstring>
#include <string>
#include <algorithm>
#include <windows.h>
#include "BinaryData.hpp"

using std::string;

class FileData : public BinaryData
{
public:

	enum ErrorType
	{
		ERR_UNDEF = -1,
		ERR_NO_ERROR,
		ERR_INVALID_HANDLE_VALUE,
		ERR_TOO_BIGGER_SIZE,
		ERR_INCORRECT_SIZE,
		ERR_NULL_SIZE,
		ERR_NO_MEMORY,
		ERR_CANT_READ,
		ERR_NOT_ALL_DATA
	};

	enum FileType
	{
	    BINARY,
	    TEXT
	};

private:
	static const char errorDescribe[][0x30];
	HANDLE       fileHandle = INVALID_HANDLE_VALUE;
	bool         isText;
	ErrorType    lastError;

public:


	// ------------------- INFO -------------------

	bool IsGood     ()  const;
	bool IsText     ()  const;

	const char* GetErrorDescribePointer () const;


	// ------------------- INIT -------------------

	void    Remove  ();

	~FileData();
	FileData ();
	FileData (const string&     newData);
	FileData (const FileData&   otherData);
	FileData (const char*       newData);
	FileData (const char*       newData,    size_t newDataSize);
	FileData (const FileType    fileType,   const string& filePath);



	// ------------------- SETTERS -------------------

	using BinaryData::SetData;          //To odblokowuje wszystkie odmiany SetData z BinaryData. W przeciwnym razie wszystko zostanie ukryte.
	using BinaryData::AppendData;

	void SetData            (const char* dataToSet);
	void SetData            (const string& dataToSet);
	void AppendData         (const char* dataToAppend);
	void AppendData         (const string& dataToAppend);


	// ------------------- OPEN AND ALLOCATE -------------------
private:
	ErrorType LoadFile (const string& path, std::size_t sizeAddition);
public:
	bool TryToLoadFile (const string& path, int sizeAddition);


	// ------------------- WRITE DATA -------------------
	bool WriteDataToFile (const char* pathPointer, std::size_t dataToWriteLength);


	// ------------------- BINARY DATA -------------------

	bool LoadBinaryFile (const string& path);
	bool SaveBinaryFile (const string& path);


	// ------------------- TEXT DATA -------------------

	bool LoadTextFile (const string& path);
	bool SaveTextFile (const string& path);


	// ------------------- OPERATORS -------------------

	FileData&	operator  = (const  FileData&  other);
	FileData&	operator += (const  FileData&  other);
	FileData	operator  + (const  FileData&  other);
};


#endif
