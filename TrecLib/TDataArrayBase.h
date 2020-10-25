#pragma once
#include "TObject.h"
class TDataArrayBase :
	public TObject
{
public:
	/**
     * Method: TDataArrayBase::TDataArrayBase
     * Purpose:
     * Parameters: const UINT s - the size of the object
     *              const UINT c - starting capacity of the object
     * Return: A blank array object
     */
	TDataArrayBase(const UINT s, const UINT c);

	/**
     * Method: TDataArrayBase::TDataArrayBase
     * Purpose: Creates a new array out of an existing one
     * Parameters: const TDataArrayBase& -  the object to copy from
     * Return: A new copy of the Array Object
     */
	TDataArrayBase(const TDataArrayBase&);

    /**
     * Method: TDataArrayBase::~TDataArrayBase
     * Purpose: Destroys the array object
     * Parameters: void
     * Return: void
     */
	~TDataArrayBase();

    /**
     * Method: TDataArrayBase::GetAnaGameType
     * Purpose: Reports the anagame type
     * Parameters: void
     * Returns: UCHAR* array expressing the type of this object
     *
     * Note: deprecated - should not be used in Anagame development
     */
	virtual UCHAR* GetAnaGameType() override;

    /**
     * Method: TDataArrayBase::Size
     * Purpose: Reports the number of elements currently held
     * Parameters: void
     * Return: UINT - the elements being held
	 * 
	 * Attributes: const
     */
	UINT Size()const;

    /**
     * Method: TDataArrayBase::Capacity
     * Purpose: Reports the size of the array being used
     * Parameters: void
     * Return: UINT - the cappacity/length of the current unerlying array
	 * 
	 * Attributes: const
     */
	UINT Capacity()const;

    /**
     * Method: TDataArrayBase::GetObjectAt
     * Purpose: Retrives the Element in raw TObject form
     * Parameters: UINT loc = the element requested
     * Return: The TObject pointer, if the type held is a TObject and the index is within bounds
     *
     * Note: Abstract in case the type is not a TObject
     */
	virtual TObject* GetObjectAt(UINT loc) = 0;
protected:
    /**
     * size: number of elements currently being held
     * capacity: size of the array, i.e. the max size possible before creating a larger array
     */
	UINT size, capacity;
};

