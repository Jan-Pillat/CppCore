
using std::string;


	// ------------------- INFO -------------------

	bool FileData::IsGood     ()  const   { return !data.IsEmpty(); }
	bool FileData::IsText     ()  const   { return (IsGood()) ?isText :false; }

	const char* FileData::GetErrorDescribePointer () const
	{
		return &errorDescribe [lastError+1][0];
	}



	// ------------------- INIT -------------------

	void    FileData::Remove  ()
	{
		data.Remove();
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
			data      = otherData.data;
			isText    = otherData.isText;
			lastError = otherData.lastError;
		}
		else
		{
			lastError = ERR_UNDEF;
		}
	}

	FileData::FileData (const char* newData, int newDataSize)
	{
		Remove ();

		data.SetData(newData, newDataSize);
		isText    = false;
		lastError = ERR_NO_ERROR;
	}

	FileData::FileData (const string& newData)
	{
		Remove ();

		data      = &newData[0];
		isText    = true;
		lastError = ERR_NO_ERROR;
	}

	// ------------------- OPEN AND ALLOCATE -------------------
	errorType FileData::LoadFile (const string& path, std::size_t sizeAddition)
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

		std::size_t fileSize = GetFileSize (fileHandle, NULL);

		if (fileSize == -1  ||  fileSize == 0)
			return ERR_INCORRECT_SIZE;

		data.CreateEmptyData(fileSize+sizeAddition);

		if (data.IsEmpty())
			return ERR_NO_MEMORY;

		std::size_t loadedCount = 0;

		if (!ReadFile (fileHandle, data.GetBeginPointer(), fileSize, &loadedCount, NULL))
			return ERR_CANT_READ;

		if (loadedCount != fileSize)
			return ERR_NOT_ALL_DATA;

		return ERR_NO_ERROR;
	}



	bool FileData::TryToLoadFile (const string& path, int sizeAddition)
	{
		errorType result = LoadFile(path, sizeAddition);

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
	bool FileData::WriteDataToFile (char* pathPointer, std::size_t dataToWriteLength)
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

		std::size_t writtenDataLength;
		bool result = WriteFile( fileHandle, data.GetBeginPointer(), dataToWriteLength, &writtenDataLength, NULL ); //Save without null char

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
		return WriteDataToFile (&path[0], data.GetLength());
	}



	// ------------------- TEXT DATA -------------------

	bool FileData::LoadTextFile (const string& path)
	{
		//Load file
		bool result = TryToLoadFile (path, 1);

		//Convert to text
		if (IsGood())
		{
			char* begin = data.GetBeginPointer();
			char* end   = data.GetBeginPointer() + data.GetLength();
			std::replace (begin, end, '\0', '\n');
			data.SetLastByte('\0');
		}
		isText = true;

		//Finish
		return result;
	}

	bool FileData::SaveTextFile (const string& path)
	{
		return WriteDataToFile (&path[0], data.GetLength()-1);
	}



	// ------------------- OPERATORS -------------------
	
	char& FileData::operator [] (std::size_t i)
	{
		return this->data[i];
	}

	FileData& FileData::operator = (const  FileData&  other)
	{
		if (this == &other) return *this;

		data      = other.data;
		isText    = other.isText;
		lastError = other.lastError;
		return *this;
	}

	FileData& FileData::operator += (const  FileData&  other)
	{
		data  += other.data;

		if (IsGood())
		{
			if (isText)
				data.ResizeBy (-1);
			
			char* begin	= data.GetEndPointer() - other.data.GetLength();
			char* end	= data.GetEndPointer();
			
			std::replace	 (begin,  end,  '\0',  '\n');
			data.SetLastByte ('\0');
		}

		return *this;
	}

	FileData FileData::operator + (const  FileData&  left,  const  FileData&  right)
	{
		FileData newFileData (left);
		newFileData += right;
		return newFileData;
	}

	bool FileData::operator == (const  FileData&  other)
	{
		if (this->data.GetLength() != other.data.GetLength())
		{
			return false;
		}

		return  !memcmp (this->data.GetBeginPointer(), other.data.GetBeginPointer(), this->data.GetLength());
	}
