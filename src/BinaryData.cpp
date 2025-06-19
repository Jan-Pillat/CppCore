
#include "../include/BinaryData.hpp"



    void BinaryData::Init ()
    {
        data    = nullptr;
		length  = 0;
    }

	void BinaryData::Remove ()
	{
		if (data) delete[] data;
		Init ();
	}




// ----- SETTERS -----

	void BinaryData::CreateEmptyData (const std::size_t lengthOfData)
	{
		Remove ();
		length  = lengthOfData;
		data    = new char [lengthOfData];
		memset (data, 0, lengthOfData);
	}

	void BinaryData::ResizeBy (const std::ptrdiff_t difference)
	{
        std::size_t absDiff = static_cast<std::size_t>(-difference);

		if (difference < 0)
		{
			if (absDiff >= length)
				Remove ();
			else
				length -= absDiff;
		}
		else
		{
			AppendData (  BinaryData(absDiff)  );
		}
	}

	void BinaryData::SetData (const char* dataToSet,  const std::size_t lengthOfData)
	{
		Remove ();
		length  = lengthOfData;
		data    = new char [lengthOfData];
		memcpy (data, dataToSet, lengthOfData);
	}

	void BinaryData::AppendData (const char* dataToAppend,  const std::size_t lengthOfData)
	{
	    // -- CONCAT --
	    std::size_t  bothLength = length + lengthOfData;
	    char*        bothData   = new char [bothLength];

	    char*        bothData_pointer  = bothData;
	    const char*  data_pointer      = data;

	    for (std::size_t i = length;  i>0;  i--)
            *bothData_pointer++ = *data_pointer++;

	    data_pointer  = dataToAppend;

	    for (std::size_t i = lengthOfData;  i>0;  i--)
            *bothData_pointer++ = *data_pointer++;

        // -- SET --
		Remove ();
		length  = bothLength;
		data    = bothData;
	}

	void BinaryData::SetData (const BinaryData& dataToSet)
	{
		SetData (dataToSet.data, dataToSet.Length());
	}

	void BinaryData::AppendData (const BinaryData& dataToAppend)
	{
		AppendData(dataToAppend.data, dataToAppend.Length());
	}

	void BinaryData::SetFristByte (const char byteToSet)
	{
		*(data) = byteToSet;
	}

	void BinaryData::SetLastByte (const char byteToSet)
	{
		*(data+length-1) = byteToSet;
	}




// ----- GETTERS -----

	std::size_t   BinaryData::Length          ()  const  {	return length;      }
	std::size_t   BinaryData::GetLength       ()  const  {	return length;      }

	char*   BinaryData::CreateAndGetCopiedData () const
	{
		char* copiedData = new char[length];

	    char* oldData_pointer   = data;
	    char* newData_pointer   = copiedData;

	    for (std::size_t i = length;  i>0;  i--)
            *newData_pointer++ = *oldData_pointer++;

		return copiedData;
	}

	char*   BinaryData::GetBeginPointer () const
	{
		return data;
	}

	char*   BinaryData::GetLastPointer () const
	{
		return data+length-1;
	}

	char*   BinaryData::GetEndPointer () const
	{
		return data+length;
	}




// ----- OPERATION -----
	void   BinaryData::Operation (const void (*func)(char* c))
	{
		char* end = GetEndPointer();
		for (char* pointer = GetBeginPointer();  pointer<end;  pointer++)
			func(pointer);
	}




// ----- INFO -----
	bool   BinaryData::IsEmpty ()  const
	{
		if (data && length>0) 	return false;	else	return true;
	}




// ----- INIT OBJECT -----

	BinaryData::BinaryData (const char* newData, const std::size_t newDataLength)
	{
		Init    ();
		SetData (newData, newDataLength);
	}

	BinaryData::BinaryData (const BinaryData& newData)
	{
		Init    ();
		SetData (newData);
	}

	BinaryData::BinaryData (const std::size_t newDataLength)
	{
		Init            ();
		CreateEmptyData (newDataLength);
	}

	BinaryData::BinaryData ()
	{
		Init    ();
	}

	BinaryData::~BinaryData ()
	{
		Remove  ();
	}



// ----- OPERATORS -----

	// -- OPERATOR  [] --
	char&		 BinaryData::operator [] (const std::size_t index)
	{
		return data[index];
	}

	const char&	 BinaryData::operator [] (const std::size_t index) const
	{
		return data[index];
	}



	// -- OPERATOR  =  --
	BinaryData&  BinaryData::operator  = (const char* str)
	{
		this->SetData(str, strlen(str));
		return *this;
	}

	BinaryData&  BinaryData::operator  = (const BinaryData& b)
	{
		if (this == &b) return *this;

		this->SetData(b);
		return *this;
	}


	// -- OPERATOR  +=  --
	BinaryData&  BinaryData::operator += (const BinaryData& b)
	{
		this->AppendData(b);
		return *this;
	}


	// -- OPERATOR  ==  --
	bool  BinaryData::operator == (const BinaryData& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		return  !memcmp (this->data, other.data, length);
	}

