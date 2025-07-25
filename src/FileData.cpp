#include "../include/FileData.hpp"

using std::string;

	const char FileData::errorDescribe[][0x30]
	{
		"UNDEFINED",
		"All correct.",
		"Can't open!  (INVALID_HANDLE_VALUE)",
		"Size is to bigger! Max is 4GB",
		"Incorrect size!  (0xFFFFFFFF)",
		"Empty file!  (size=0x0)",
		"NO MEMORY!",
		"Can't read file!",
		"Not all data has been loaded!"
	};


	// ------------------- INFO -------------------

	bool FileData::IsGood     ()  const   { return !IsEmpty(); }
	bool FileData::IsText     ()  const   { return (IsGood()) ?isText :false; }

	const char* FileData::GetErrorDescribePointer () const
	{
		return &errorDescribe [lastError+1][0];
	}



	// ------------------- INIT -------------------

	void    FileData::Remove  ()
	{
		BinaryData::Remove();
		lastError = ERR_NO_ERROR;

		if (fileHandle != INVALID_HANDLE_VALUE )
		{
			CloseHandle (fileHandle);
			fileHandle = INVALID_HANDLE_VALUE;
		}
	}


	FileData::~FileData()
	{
		Remove ();
	}

	FileData::FileData ()
	{
		Remove ();
	}

	FileData::FileData (const FileData& otherData)
	{
		Remove ();

		if (otherData.IsGood())
		{
            SetData  (otherData);
			isText    = otherData.isText;
			lastError = otherData.lastError;
		}
		else
		{
			lastError = ERR_UNDEF;
		}
	}

	FileData::FileData (const FileData::FileType fileType, const string& filePath)
	{
		if (fileType == BINARY)
            LoadBinaryFile (filePath);
        else
            LoadTextFile (filePath);
	}

	FileData::FileData (const char* newData, size_t newDataSize)
	{
		SetData  (newData, newDataSize);
		isText    = false;
		lastError = ERR_NO_ERROR;
	}

	FileData::FileData (const char* newData)
	{
		SetData  (newData, strlen(newData)+1);
		isText    = true;
		lastError = ERR_NO_ERROR;
	}

	FileData::FileData (const string& newData)
	{
		SetData (&newData[0], newData.length()+1);
		isText    = true;
		lastError = ERR_NO_ERROR;
	}



	// ------------------- DATA -------------------
	void FileData::SetData (const char* dataToSet)
	{
        isText = true;
        SetData (dataToSet, strlen(dataToSet)+1);
	}

	void FileData::AppendData (const char* dataToAppend)
	{
	    if (data != nullptr)
        {
            isText = true;
            AppendData(dataToAppend, strlen(dataToAppend)+1);
        }
        else if (isText)
        {
            ResizeBy(-1);
            AppendData(dataToAppend, strlen(dataToAppend)+1);
        }
        else
        {
            AppendData(dataToAppend, strlen(dataToAppend));
        }
	}

	void FileData::SetData (const string& dataToSet)
	{
        FileData::SetData (&dataToSet[0]);
	}

	void FileData::AppendData (const string& dataToAppend)
	{
        FileData::AppendData (&dataToAppend[0]);
	}



	// ------------------- OPEN AND ALLOCATE -------------------
	FileData::ErrorType FileData::LoadFile (const string& path, std::size_t sizeAddition)
	{
		Remove();  //If some data is loaded, it will be removed for new data.

		fileHandle = CreateFile (&path[0],        //File path
								 GENERIC_READ,    //The target is read data.
								 FILE_SHARE_READ, //Other programs can also read this file.
								 NULL,            //NOT IMPORTANT
								 OPEN_EXISTING,   //Opens file, and if it not exist, returns error.
								 NULL,            //NOT IMPORTANT
								 NULL);           //NOT IMPORTANT

		if (fileHandle == INVALID_HANDLE_VALUE )
			return ERR_INVALID_HANDLE_VALUE;

		DWORD  highPart     = 0;
		DWORD  lowPart      = GetFileSize (fileHandle, &highPart);
        UINT64 fullFileSize = (static_cast<UINT64>(highPart)<<32) | lowPart;
        DWORD  fileSize     = lowPart;

		if (fullFileSize > (1ULL<<(sizeof(DWORD)*8))-1 ) //if (fullFileSize > DWORD_MAX)
			return ERR_TOO_BIGGER_SIZE;

		if (fileSize == -1)
			return ERR_INCORRECT_SIZE;

		if (fileSize == 0)
			return ERR_NULL_SIZE;

		CreateEmptyData(fileSize+sizeAddition);

		if (IsEmpty())
			return ERR_NO_MEMORY;

		DWORD loadedCount = 0;

		if (!ReadFile (fileHandle, GetBeginPointer(), fileSize, &loadedCount, NULL))
			return ERR_CANT_READ;

		if (loadedCount != fileSize)
			return ERR_NOT_ALL_DATA;

		return ERR_NO_ERROR;
	}



	bool FileData::TryToLoadFile (const string& path, int sizeAddition)
	{
		ErrorType result = LoadFile(path, sizeAddition);

		if (result != ERR_NO_ERROR)
		{
			Remove ();
			lastError = result;
			return false;
		}

		CloseHandle (fileHandle);
		return true;
	}



	// ------------------- WRITE DATA -------------------
	bool FileData::WriteDataToFile (const char* pathPointer, std::size_t dataToWriteLength)
	{
		fileHandle = CreateFile (pathPointer,     //File path
								 GENERIC_WRITE,   //The target is write data.
								 NULL,            //Other programs can't touch the file.
								 NULL,            //NOT IMPORTANT
								 CREATE_ALWAYS,   //Opens file, and if it not exist, returns error.
								 NULL,            //NOT IMPORTANT
								 NULL);           //NOT IMPORTANT

		if (fileHandle == INVALID_HANDLE_VALUE )
			return false;

		DWORD writtenDataLength = 0;
		char* dataPointer = GetBeginPointer();
		bool result = true;
		while (dataToWriteLength > 0  &&  result==true)
        {
            result               = WriteFile( fileHandle, dataPointer, dataToWriteLength, &writtenDataLength, NULL ); //Save without null char
            dataToWriteLength   -= writtenDataLength;
            dataPointer         += writtenDataLength;
        }

		CloseHandle (fileHandle);
		fileHandle = INVALID_HANDLE_VALUE;

		return result;
	}


	// ------------------- BINARY DATA -------------------

	bool FileData::LoadBinaryFile (const string& path)
	{
		return TryToLoadFile (path, 0);
	}

	bool FileData::SaveBinaryFile (const string& path)
	{
		return WriteDataToFile (&path[0], length);
	}



	// ------------------- TEXT DATA -------------------

	bool FileData::LoadTextFile (const string& path)
	{
		//Load file
		bool result = TryToLoadFile (path, 1);

		//Convert to text
		if (IsGood())
		{
			std::replace (GetBeginPointer(), GetEndPointer(), '\0', '\n');
			SetLastByte('\0');
		}
		isText = true;

		//Finish
		return result;
	}

	bool FileData::SaveTextFile (const string& path)
	{
		return WriteDataToFile (&path[0], length-1);
	}



	// ------------------- OPERATORS -------------------

	FileData& FileData::operator = (const  FileData&  other)
	{
		if (this == &other) return *this;

		SetData  (other);
		isText    = other.isText;
		lastError = other.lastError;
		return *this;
	}

	FileData& FileData::operator += (const  FileData&  other)
	{
        if (isText)
            ResizeBy (-1);

        AppendData(other);

		if (IsGood())
		{
		    if (!other.isText)
            {
                char* begin	= GetEndPointer() - other.GetLength();
                char* end	= GetEndPointer();
                std::replace	 (begin,  end,  '\0',  '\n');
            }
			SetLastByte ('\0');
		}

		return *this;
	}

	FileData FileData::operator + (const  FileData&  other)
	{
		FileData newFileData (*this);
		newFileData += other;
		return newFileData;
	}
