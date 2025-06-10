#ifndef _HPP_FileData_
#define _HPP_FileData_

#include <cstddef>
#include <cstring>
#include <algorithm>
#include <windows.h>
#include "BinaryData.hpp"

using std::string;

class FileData
{
private:

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

	static const char errorDescribe[][0x30];


	HANDLE       fileHandle;
	bool         isText;
	ErrorType    lastError;

public:
	BinaryData  data;


	// ------------------- INFO -------------------

	bool IsGood     ()  const;
	bool IsText     ()  const;

	const char* GetErrorDescribePointer () const;


	// ------------------- INIT -------------------

	void    Remove  ();

	~FileData();
	FileData ();
	FileData (const FileData& otherData);
	FileData (const char* newData, int newDataSize);
	FileData (const string& newData);


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

	char&		operator [] (std::size_t i);
	FileData&	operator  = (const  FileData&  other);
	FileData&	operator += (const  FileData&  other);
	FileData	operator  + (const  FileData&  other);
	bool		operator == (const  FileData&  other);
};


#endif
