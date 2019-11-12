#pragma once

#include "TString.h"
#include "TDataArrayBase.h"

#include <vector>



/*
* Class TDataArray (Regular Type version)
* AnaGame array designed to hold raw data
*/
template<typename T> class  TDataArray : public TDataArrayBase
{
	friend class TDataArray<T>;
private:
	T* array;
	// UINT size, capacity;

public:
	/*
	* Method: (TDataArray) (Constructor)
	* Purpose: Sets up a TDataArray based off an existing one
	* Parameters: TDataArray<T>& newArray - the Data Array to copy
	* Returns: void
	*/
	TDataArray(const TDataArray<T>& newArray) : TDataArrayBase(newArray.Size(), newArray.Capacity())
	{
		array = new T[newArray.Capacity()];
		
		for (UINT c = 0; c < newArray.Size() && c < newArray.Capacity(); c++)
		{
			if (c < newArray.Capacity())
				array[c] = newArray.array[c];
		}
		//memcpy_s(array, capacity, newArray.GetArray(), capacity);
	}

	/*
	* Method: TDataArray - data
	* Purpose: Retrieves the location of the underlying array
	* Parameters: void
	* Returns: T* data address in memory
	*/
	T* data()
	{
		return array;
	}

	/*
	* Method: TDataArray - operator[]
	* Purpose: Gives the TDataArray array like functionality
	* Parameters: size_t c - index to target
	* Returns: T& - element at index
	*/
	T& operator[](size_t c)
	{
		if (c >= size)
			throw new TString(L"IndexOutOfBounds");
		return array[c];
	}

	/*
	* Method: TDataArray - operator=
	* Purpose: Copies the contents of an exisitng data array to the TDataArray
	* Parameters: TDataArray<T>& newArray - the Data Array to copy
	* Returns: void
	*/
	void operator=(const TDataArray<T>& newArray)
	{
		if (array)
			delete[] array;
		capacity = newArray.Capacity();
		array = new T[capacity];
		size = newArray.Size();
		
		for (UINT c = 0; c < size && c < capacity; c++)
		{
			if(c < capacity)
			array[c] = newArray.array[c];
		}//memcpy_s(array, capacity, newArray.GetArray(), capacity);
	}

	/*
	* Method: TDataArray - at
	* Purpose: returns element at a given index
	* Parameters: UINT c - the index to target
	* Returns: T& - element at index
	*/
	T& at(UINT c)
	{
		if (c >= size)
			throw new TString(L"IndexOutOfBounds");
		return array[c];
	}

	/*
	* Method: TDataArray - operator=
	* Purpose: Copies the contents of a C++ standard vector to the TDataArray
	* Parameters: std::vector<T, std::allocator<T>>& vectorSource - the vector to copy
	* Returns: void
	*/
	void operator=(const std::vector<T, std::allocator<T>>& vectorSource)
	{
		if (array)
			delete[] array;
		capacity = vectorSource.capacity();
		array = new T[capacity];
		size = vectorSource.size();
		for (UINT c = 0; c < vectorSource.capacity(); c++)
			array[c] =vectorSource[c];
	}

	/*
	* Method: (TDataArray) (Constructor)
	* Purpose: Sets up a TDataArray
	* Parameters: void
	* Returns: void
	*/
	TDataArray() : TDataArrayBase(0, 5)
	{
		array = new T[5];
	}



	/*
	* Method: (TDataArray) (Destructor)
	* Purpose: Cleans up the Data Array
	* Parameters: void
	* Returns: void
	*/
	~TDataArray()
	{
		delete[] array;	
	}

	

	/*
	* Method: TDataArray - Capacity
	* Purpose: Reports the size of the underlying array
	* Parameters: void
	* Returns: UINT - the size of the unerlying array being used
	*/
	UINT Capacity() const
	{
		return capacity;
	}

	/*
	* Method: TDataArray - push_back
	* Purpose: Appends an element to the DataArray
	* Parameters: T element - the data to append
	* Returns: UINT - the new size of the DataArray
	*/
	UINT push_back(T element)
	{
		if (size >= capacity)
		{
			T* newArray = new T[capacity + 5];
			for (UINT c = 0; c < capacity; c++)
				newArray[c] = array[c];
			//memcpy_s(newArray, capacity, array, capacity);
			delete[] array;
			array = newArray;
			capacity += 5;
		}
		array[size++] = element;
		return size - 1;
	}

	/*
	* Method: TDataArray - RemoveAt
	* Purpose: Removes an element at a certain location
	* Parameters: UINT c - the location to remove
	* Returns: T - the data stored at that location
	*/
	T RemoveAt(UINT c)
	{
		if (c >= size)
			throw new TString(L"IndexOutOfBounds");
		T returnable = array[c];

		for (; c < size - 1; c++)
			array[c] = array[c + 1];
		size--;
		return returnable;
	}

	/*
	* Method: TDataArray - RemoveAll
	* Purpose: Removes all emements and sets count to 0
	* Parameters: void
	* Returns: void
	*/
	void RemoveAll()
	{
		if (array)
			delete[] array;
		array = new T[capacity = 5];
		size = 0;
	}

	TObject* GetObjectAt(UINT loc)
	{
		return nullptr;
	}
};

/*
* Class TDataArray (Pointer Type Version)
* AnaGame Array designed to hold raw pointers to data 
*/
template<typename T> 
class  TDataArray<T*> : public TDataArrayBase
{
	friend class TDataArray<T*>;
private:
	T** array;
	 // UINT size, capacity;

public:

	/*
	* Method: TDataArray - data
	* Purpose: Retrieves the location of the underlying array
	* Parameters: void
	* Returns: T* data address in memory
	*/
	T** data() const
	{
		return array;
	}

	/*
	* Method: TDataArray - operator[]
	* Purpose: Gives the TDataArray array like functionality
	* Parameters: size_t c - index to target
	* Returns: T& - element at index
	*/
	T* operator[](size_t c)
	{
		if (c >= size)
			throw new TString(L"IndexOutOfBounds");
		return array[c];
	}

	bool setAt(T* obj, size_t c)
	{
		if (c >= size)
			throw new TString(L"IndexOutOfBounds");
		array[c] = obj;
	}

	/*
	* Method: TDataArray - operator=
	* Purpose: Copies the contents of an exisitng data array to the TDataArray
	* Parameters: TDataArray<T>& newArray - the Data Array to copy
	* Returns: void
	*/
	void operator=(TDataArray<T*>& newArray)
	{
		if (array)
			delete[] array;
		capacity = newArray.Capacity();
		array = new T*[capacity];
		size = newArray.Size();

		for (UINT c = 0; c < size && c < capacity; c++)
		{
			if (c < capacity)
				array[c] = newArray[c];
		}//memcpy_s(array, capacity, newArray.GetArray(), capacity);
	}

	/*
	* Method: TDataArray - at
	* Purpose: returns element at a given index
	* Parameters: UINT c - the index to target
	* Returns: T& - element at index
	*/
	T* at(UINT c)
	{
		if (c >= size)
			throw new TString(L"IndexOutOfBounds");
		return array[c];
	}

	/*
	* Method: TDataArray - operator=
	* Purpose: Copies the contents of a C++ standard vector to the TDataArray
	* Parameters: std::vector<T, std::allocator<T>>& vectorSource - the vector to copy
	* Returns: void
	*/
	void operator=(std::vector<T*, std::allocator<T*>>& vectorSource)
	{
		if (array)
			delete[] array;
		capacity = vectorSource.capacity();
		array = new (T*)[capacity];
		size = vectorSource.size();
		for (UINT c = 0; c < vectorSource.capacity(); c++)
			array[c] = vectorSource[c];
	}

	/*
	* Method: (TDataArray) (Constructor)
	* Purpose: Sets up a TDataArray
	* Parameters: void
	* Returns: void
	*/
	TDataArray<T*>() : TDataArrayBase(0, 5)
	{	
		array = new T*[5];

	}

	/*
	* Method: (TDataArray) (Constructor)
	* Purpose: Sets up a TDataArray based off an existing one
	* Parameters: TDataArray<T>& newArray - the Data Array to copy
	* Returns: void
	*/
	TDataArray(TDataArray<T>& newArray) : TDataArrayBase(newArray.Size(), newArray.Capacity())
	{
		array = new (T*)[newArray.Capacity()];

		for (UINT c = 0; c < newArray.Size() && c < newArray.Capacity(); c++)
			if (c < newArray.Capacity())
				array[c] = newArray[c];
		//memcpy_s(array, capacity, newArray.GetArray(), capacity);
	}

	/*
	* Method: (TDataArray) (Destructor)
	* Purpose: Cleans up the Data Array
	* Parameters: void
	* Returns: void
	*/
	~TDataArray()
	{
		delete[] array;
	}



	/*
	* Method: TDataArray - Capacity
	* Purpose: Reports the size of the underlying array
	* Parameters: void
	* Returns: UINT - the size of the unerlying array being used
	*/
	UINT Capacity()
	{
		return capacity;
	}

	/*
	* Method: TDataArray - push_back
	* Purpose: Appends an element to the DataArray
	* Parameters: T element - the data to append
	* Returns: UINT - the new size of the DataArray
	*/
	UINT push_back(T* element)
	{
		if (size >= capacity)
		{
			T** newArray = new T*[capacity + 5];
			for (UINT c = 0; c < capacity; c++)
				newArray[c] = array[c];
			//memcpy_s(newArray, capacity, array, capacity);
			delete[] array;
			array = newArray;
			capacity += 5;
		}
		array[size++] = element;
		return size - 1;
	}

	/*
	* Method: TDataArray - RemoveAt
	* Purpose: Removes an element at a certain location
	* Parameters: UINT c - the location to remove
	* Returns: T - the data stored at that location
	*/
	T* RemoveAt(UINT c)
	{
		if (c >= size)
			throw new TString(L"IndexOutOfBounds");
		T* returnable = array[c];

		for (; c < size - 1; c++)
			array[c] = array[c + 1];
		size--;
		return returnable;
	}

	/*
	* Method: TDataArray - RemoveAll
	* Purpose: Removes all emements and sets count to 0
	* Parameters: void
	* Returns: void
	*/
	void RemoveAll()
	{
		if (array)
			delete[] array;
		array = new T*[capacity = 5];
		size = 0;
	}

	TObject* GetObjectAt(UINT loc)
	{
		try
		{
			return dynamic_cast<TObject*>(at(loc));
		}
		catch (...)
		{
			return nullptr;
		}
	}
};
