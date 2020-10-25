#include "TDataArrayBase.h"

/**
 * Method: TDataArrayBase::TDataArrayBase
 * Purpose:
 * Parameters: const UINT s - the size of the object
 *              const UINT c - starting capacity of the object
 * Return: A blank array object
 */
TDataArrayBase::TDataArrayBase(const UINT s, const UINT c)
{
	size = s;
	capacity = c;
}
/**
 * Method: TDataArrayBase::TDataArrayBase
 * Purpose: Creates a new array out of an existing one
 * Parameters: const TDataArrayBase& -  the object to copy from
 * Return: A new copy of the Array Object
 */
TDataArrayBase::TDataArrayBase(const TDataArrayBase& copy)
{
	size = copy.Size();
	capacity = copy.Capacity();
}

/**
 * Method: TDataArrayBase::~TDataArrayBase
 * Purpose: Destroys the array object
 * Parameters: void
 * Return: void
 */
TDataArrayBase::~TDataArrayBase()
{
}

/**
 * Method: TDataArrayBase::GetAnaGameType
 * Purpose: Reports the anagame type
 * Parameters: void
 * Returns: UCHAR* array expressing the type of this object
 *
 * Note: deprecated - should not be used in Anagame development
 */
UCHAR * TDataArrayBase::GetAnaGameType()
{
	return TDataArrayType;
}

/**
 * Method: TDataArrayBase::Size
 * Purpose: Reports the number of elements currently held
 * Parameters: void
 * Return: UINT - the elements being held
 */
UINT TDataArrayBase::Size() const
{
	return size;
}

/**
 * Method: TDataArrayBase::Capacity
 * Purpose: Reports the size of the array being used
 * Parameters: void
 * Return: UINT - the cappacity/length of the current unerlying array
 */
UINT TDataArrayBase::Capacity() const
{
	return capacity;
}
