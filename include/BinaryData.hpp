#ifndef _HPP_BinaryData_
#define _HPP_BinaryData_

#include <cstddef>

class BinaryData
{
private:
	char*         data;
	std::size_t   length;

public:

    void Init   ();
	void Remove ();

// ----- SETTERS -----
	void CreateEmptyData    (const std::size_t lengthOfData);
	void ResizeBy           (const std::ptrdiff_t difference);

	void SetData            (const char* dataToSet,    const std::size_t lengthOfData);
	void AppendData         (const char* dataToAppend, const std::size_t lengthOfData);

	void SetData            (const BinaryData& dataToSet);
	void AppendData         (const BinaryData& dataToAppend);

	void SetFristByte       (const char byteToSet);
	void SetLastByte        (const char byteToSet);

	template <typename T> void Set        (const T dataToSet)
	{
		SetData (reinterpret_cast<const char*>(&dataToSet), sizeof(dataToSet));
	}
	template <typename T> void Append     (const T dataToAppend)
	{
		AppendData (reinterpret_cast<const char*>(&dataToAppend), sizeof(dataToAppend));
	}

// ----- GETTERS -----
	std::size_t   Length                  ()  const;
	std::size_t   GetLength               ()  const; // GetLength() – alias for Length(), more explicit in intention
	char*         CreateAndGetCopiedData  ()  const; // Returns pointer to allocated new buffer

	char*         GetBeginPointer         ()  const;
	char*         GetLastPointer          ()  const;
	char*         GetEndPointer           ()  const;

// ----- OPERATION -----
	void          Operation (const void (*func)(char* c));

// ----- INFO -----
	bool          IsEmpty   ()  const;

// ----- INIT -----
	BinaryData  (const char* newData, const std::size_t newDataLength);
	BinaryData  (const BinaryData& newData);
	BinaryData  (const std::size_t newDataLength);
	BinaryData  ();
	~BinaryData ();
	template <typename T> BinaryData (const T newData)
	{
		SetData (reinterpret_cast<const char*>(&newData), sizeof(newData));
	}

// ----- OPERATORS -----
	char&		operator [] (const std::size_t index);
	const char&	operator [] (const std::size_t index) const;
	BinaryData& operator  = (const char* str);
	BinaryData& operator  = (const BinaryData& b);
	BinaryData& operator += (const BinaryData& b);

	template <typename T> BinaryData& operator  = (const T dataToSet)
	{
		this->SetData(&dataToSet, sizeof(dataToSet));
		return *this;
	}
	template <typename T> BinaryData& operator += (const T dataToAppend)
	{
		this->Append(dataToAppend);
		return *this;
	}
};


#endif
