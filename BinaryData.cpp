#ifndef _BinaryData_
#define _BinaryData_
class BinaryData
{
private:
	char* data;
	int   length;

	char* getNullCharPos (char* s)
	{
		while (*s != 0) s++;
		return s;
	}

public:

    void BinaryData_Init ()
    {
        data    = nullptr;
		length  = 0;
    }

	void Remove ()
	{
		if (data) delete data;
		BinaryData_Init ();
	}

	void SetData (const char* newData, const int newLength)
	{
		Remove ();
		length  = newLength;
		data    = new char [newLength];
		for (register int i = 0;  i<newLength;  i++) data[i] = newData[i];
	}

	void AddData (char* newData, int newLength)
	{
	    // -- CONCAT --
	    int   bothLength = length + newLength;
	    char* bothData   = new char [bothLength];

	    char* bothData_pointer  = bothData;
	    char* data_pointer      = data;

	    for (int i = length;  i>0;  i--)
            *bothData_pointer++ = *data_pointer++;

	    data_pointer             = newData;

	    for (int i = newLength;  i>0;  i--)
            *bothData_pointer++ = *data_pointer++;

        // -- SET --
		Remove ();
		length  = bothLength;
		data    = bothData;
	}

	void AddData (int integerToSave)
	{
	    // -- CONCAT --
	    char* newData   = new char [length+4];

	    char* newData_pointer   = newData;
	    char* data_pointer      = data;

	    for (int i = length;  i>0;  i--)
            *newData_pointer++ = *data_pointer++;

        *(int*)newData_pointer = integerToSave;

        // -- SET --
		Remove ();
		length += 4;
		data    = newData;
	}

	BinaryData (const char* newData, const int newLength)
	{
		BinaryData_Init ();
		SetData (newData, newLength);
	}

	BinaryData ()
	{
		BinaryData_Init ();
	}

	~BinaryData ()
	{
		if (data) delete data;
	}

	int   Length          ()    {	return length;      }
	int   getDataLength   ()    {	return length;      }
	char* getData         ()    {	return &data[0];    }

	char&		operator [] (int   i)				{ return data[i];											}

//	BinaryData& operator  = (unsigned char  c)	{ this->SetData(&c, 1);					return *this;		}
	BinaryData& operator  = (char  c)				{ this->SetData(&c, 1);					return *this;		}
	BinaryData& operator  = (char* s)				{ this->SetData(s, getNullCharPos(s)-s);return *this;		}

	BinaryData& operator  = (BinaryData& b)
	{
		if (this == &b) return *this;

		this->SetData(&b.data[0], b.Length());

		return *this;
	}

	BinaryData& operator += (BinaryData& b)
	{
	    BinaryData new1 (b.data, b.Length());
		if (this == &b) return *this;

		this->SetData(&b.data[0], b.Length());

		return *this;
	}
};
#endif
