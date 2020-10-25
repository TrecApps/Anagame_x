#pragma once
#include "TDataArray.h"
#include "TObject.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include "TrecReference.h"

#define T_NO_ERROR 0
#define T_OVERFLOW 1
#define NOT_NUMB 2

/*
* ColorFormat
* Used to keep track of how the color originally was presented
*/
typedef enum  ColorFormat
{
	cform_hex,
	cform_hexa,
	cform_rgb,
	cform_rgba,
	cform_hsl,
	cform_hsla,
	cform_ana,
	cform_ana_a
}ColorFormat;

typedef struct IndexRange {
	int start;
	int end;
}IndexRange;


/*
* Class: TString
* Represents the UNICODE version of the String class, with features such as split,
*	number extraction, substring, and trim
*/
class  TString : public TObject
{
public:

	/**
	 * Method: TString::GetType
	 * Purpose: Returns a String Representation of the object type
	 * Parameters: void
	 * Returns: TString - representation of the object type
	 */
	virtual TString GetType()override;

	/*
	* Method: TString::Constructor
	* Purpose: Default Constructor for the TString Class
	* Parameters: void
	* Returns: void
	*/
	TString();

	/*
	* Method: TString::Destructor
	* Purpose: Cleans up the TString
	* Parameters: void
	* Returns: void
	*/
	~TString();

	/*
	* Method: TString::Constructor
	* Purpose: Uses a pointer to another TString to build this one
	* Parameters: TString* orig - pointer to TString to copy
	* Returns: void
	*/
	TString(const TString*);

	/*
	* Method: TString::Constructor
	* Purpose: Uses a C-String  to construct TString
	* Parameters: const char* cps - C-String to copy
	* Returns: void
	*/
	TString(const char*);

	/*
	* Method: TString::Constructor
	* Purpose: Builds a TString off of a wide char array
	* Parameters: const WCHAR* wcps - Wide Character array to copy
	* Returns: void
	*/
	TString(const WCHAR*);

	/*
	* Method: TString::Constructor
	* Purpose: Uses a reference to another TString to build this one
	* Parameters: TString* orig - reference to TString to copy
	* Returns: void
	*/
	TString(const TString& c);

	/*
	* Method: TString::Constructor
	* Purpose: Uses a reference to an existing C++ String to build the TString
	* Parameters: CString* cps - reference to C++ String to copy
	* Returns: void
	*/
	TString(std::string& str);

	/*
	* Method: TString::Constructor
	* Purpose: Uses a single WCHAR to build the TString
	* Parameters: WCHAR c - the Character to set the TString equal to
	* Returns: void
	*/
	TString(WCHAR c);

	/*
	* Method: TString::ConvertToInt
	* Purpose: Converts a Compliant TString into an integer
	* Parameters: int* value - the value to store
	* Returns: short - 0 if successful, error code otherwise
	*/
	short ConvertToInt(int&);

	/*
	 * Method: TString::ConvertToInt
	 * Purpose: Converts a Compliant TString into an integer
	 * Parameters: long* value - the value to store
	 * Returns: short - 0 if successful, error code otherwise
	 */
	short ConvertToInt(long& value);

	/*
	* Method: TString::ConvertToDouble
	* Purpose: Converts a Compliant TString into a double floating point number
	* Parameters: double* value - the value to store
	* Returns: short - 0 if successful, error code otherwise
	*/
	short ConvertToDouble(double&);

	/*
	* Method: TString::ConvertToLong
	* Purpose: Converts a Compliant TString into a long integer
	* Parameters: long* value - the value to store
	* Returns: short - 0 if successful, error code otherwise
	*/
	short ConvertToLong(long long&);

	/*
	* Method: TString::ConvertToFloat
	* Purpose: Converts a Compliant TString into a float
	* Parameters: float* value - the value to store
	* Returns: short - 0 if successful, error code otherwise
	*/
	short ConvertToFloat(float&);

	/*
	* Method: TString::split
	* Purpose: Splits a String by the provided deliniators
	* Parameters: TString str - the TString holding deliniators
	*			UCHAR flags - flags to use to control the behavior of this method
				WCHAR exitQuote - quote to look for if String is believed to begin in quotes
	* Returns: TrecPointer<TArray<TString>> - Array of TStrings holding tokens
	*
	* flags: 0b00000001 - t_file_check_back_slash - ignore a hit if odd number of backslashes are present
	*		 0b00000010 - t_file_out_of_quotes	  - ignore hits found within a quotation string
	*		 0b00000100 - t_file_starts_in_quote  - assume that String starts within a quote
	* 
	* Attributes: const
	*/
	TrecPointer<TDataArray<TString>> split(TString, UCHAR flags = 0, WCHAR exitQuote = L'\"') const;

	/*
	* Method: TString::splitn
	* Purpose: Splits a String by the provided deliniators, providing a limit as to how many times the string can be split
	* Parameters: TString str - the TString holding deliniators
	*			UINT elements - the max number of elements to split by (0 for no limit)
	*			UCHAR flags - flags to use to control the behavior of this method
				WCHAR exitQuote - quote to look for if String is believed to begin in quotes
	* Returns: TrecPointer<TArray<TString>> - Array of TStrings holding tokens
	*
	* flags: 0b00000001 - t_file_check_back_slash - ignore a hit if odd number of backslashes are present
	*		 0b00000010 - t_file_out_of_quotes	  - ignore hits found within a quotation string
	*		 0b00000100 - t_file_starts_in_quote  - assume that String starts within a quote
	*
	* Attributes: const
	*/
	TrecPointer<TDataArray<TString>> splitn(TString, UINT elements = 0, UCHAR flags = 0, WCHAR exitQuote = L'\"') const;

	/**
	 * Method: TString::IsBackslahedChar
	 * Purpose: Reports whether the character indexed has an odd number of backslashes in front of it
	 * Parameters: UINT index - the index to start
	 * returns: bool - whether there are an odd number of backslashes infron of the characetr in the index
	 */
	bool IsBackSlashChar(UINT index);

	/*
	* Method: TString::GetBufferCopy
	* Purpose: Gets a copy of the Raw Buffer
	* Parameters: void
	* Returns: WCHAR* - the copy of the TStrings buffer
	*
	* Note: the data returned was initialized via new[] and thereforem you need to call delete[] on it. It is recommended you
	*		use "GetConstantBuffer()" wherever possible
	* 
	* Attributes: const
	*/
	WCHAR* GetBufferCopy()const ;

	/*
	 * Mehtod: TString::GetConstantBuffer
	 * Purpose: Returns the underlying String
	 * Parameters: void
	 * Returns: const WCHAR* - a constant pointer of the underlying string buffer
	* 
	* Attributes: const
	 */
	const WCHAR* GetConstantBuffer() const;

	/*
	* Method: TString::SubString
	* Purpose: Returns a substring specified
	* Parameters: UINT beginningIndex - the index to start at
	*			int endIndex - exclusive index to end (use negative value to go to end)
	* Returns: TString::the Substring generated
	* 
	* Attributes: const
	*/
	TString SubString(UINT beginningIndex, int endIndex = -1) const;


	/*
	* Method: TString::ConvertToColor
	* Purpose: Converts the string into a Direct2D color representation
	* Parameters: D2D1_COLOR_F & color - the color to generate
	*			ColorFrmat& cf - the Color Format detected in the string
	* Returns: bool - success if true, false if TString doesn't hold a color
	*/
	bool ConvertToColor(D2D1_COLOR_F& color, ColorFormat& cf);

	/**
	 * Method: TString::FindOutOfQuotes
	 * Purpose: Performs the find operation while ignoring hits found within quotation marks
	 * Parameters: const TString& subString - the substring to search for
	 *				 int start - location to start the search
	 *				 bool ignoreEscape - whether to ignore escape characters
	 * Returns: int - the index of the substring found (-1 if not found)
	 */
	int FindOutOfQuotes(const TString& subString, int start = 0, bool ignoreEscape = true) const;

	// Set Methods, to be used in place of Assignment operators to avoid C26444 Warnings


	/**
	 * Method: TString::Set
	 * Purpose: Sets the contents of the string to the specified string
	 * Parameters: const TString& t - the string to set to
	 * Returns: void
	 */
	void Set(const TString& s);

	/**
	 * Method: TString::Set
	 * Purpose: Sets the contents of the string to the specified raw string
	 * Parameters: const TString* s - the raw string to set to
	 * Returns: void
	 */
	void Set(const TString* s);

	/**
	 * Method: TString::Set
	 * Purpose: Sets the contents of the string to the specified raw string
	 * Parameters: const WCHAR* w - the raw string to set to
	 * Returns: void
	 */
	void Set(const WCHAR* w);

	/**
	 * Method: TString::Set
	 * Purpose: Sets the contents of the string to the specified character
	 * Parameters: WCHAR w - the character to set to
	 * Returns: void
	 */
	void Set(const WCHAR w);


	/*
	 * Method: TString::operator=
	 * Purpose: Assigns an Existing TString to this TString
	 * Parameters: TString& t - the TString to copy
	 * Returns: void
	 */
	TString operator=(const TString&);
	/*
	* Method: TString::operator=
	* Purpose: Assigns an Existing TString to this TString
	* Parameters: TString* s - the TString to copy
	* Returns: void
	*/
	TString operator=(const TString* s);
	/*
	* Method: TString::operator=
	* Purpose: Assigns an existing wide string to this TString
	* Parameters: WCHAR* w - the wide string to copy
	* Returns: void
	*/
	TString operator=(const WCHAR* w);
	/*
	* Method: TString::operator=
	* Purpose: Assigns a WCHAR to this TString
	* Parameters: WCHAR w - the Character to copy
	* Returns: void
	*/
	TString operator=(const WCHAR w);
	/*
	* Method: TString::operator+
	* Purpose: Adds the contents of an existing TString to this one
	* Parameters: TString& t - the TString to append
	* Returns: void
	* 
	* Attributes: const
	*/
	TString operator+(const TString&) const;
	/*
	* Method: TString::operator+
	* Purpose: Adds the contents of an existing TString to this one
	* Parameters: TString& t - the TString to append
	* Returns: void
	* 
	* Attributes: const
	*/
	TString operator+(const TString*) const;
	/*
	* Method: TString::operator+
	* Purpose: Adds the contents of an existing wide string to this one
	* Parameters: WCHAR* w - the wide string to append
	* Returns: void
	* 
	* Attributes: const
	*/
	TString operator+(const WCHAR*)const;
	/**
	 * Method: TString::operator+
	 * Purpose: Returns a version of this string with the character appended
	 * Parameters: WCHAR w -the character to append
	 * Returns: TString version of the string with the appended character
	 * 
	 * Attributes: const
	 */
	TString operator+(const WCHAR w)const;
	/*
	* Method: TString::operator+=
	* Purpose: Adds the contents of an existing TString to this one
	* Parameters: TString& t - the TString to append
	* Returns: void
	*/
	TString operator+=(const TString&);
	/*
	* Method: TString::operator+=
	* Purpose: Adds the contents of an existing TString to this one
	* Parameters: TString& t - the TString to append
	* Returns: void
	*/
	TString operator+=(const TString*);
	/*
	* Method: TString::operator+=
	* Purpose: Adds the contents of an existing wide string to this one
	* Parameters: WCHAR* w - the wide string to append
	* Returns: void
	*/
	TString operator+=(const WCHAR*);
	/**
	 * Method: TString::operator+=
	 * Purpose: Appends the WCHAR to the string
	 * Parameters: WCHAR w
	 * Returns: TString::the result of the append operation
	 */
	TString operator+=(const WCHAR w);

	//void operator+=(TString*);
	//void operator


	/*
	 * Method: TString::operator==
	 * Purpose: Conpares the TString with a TString and returns true if contents are equal
	 * Parameters: TString& s - the string to compare
	 * Returns: bool - result of comparison
	 */
	bool operator==(TString& s);
	/*
	* Method: TString::operator==
	* Purpose: Conpares the TString with a TString and returns true if contents are equal
	* Parameters: TString* s - the string to compare
	* Returns: bool - result of comparison
	*/
	bool operator==(TString* s);
	/*
	* Method: TString::operator==
	* Purpose: Conpares the TString with a wide string and returns true if contents are equal
	* Parameters: WCHAR* s - the string to compare
	* Returns: bool - result of comparison
	*/
	bool operator==(WCHAR* s);


	/*
	* Method: TString::operator!=
	* Purpose: Conpares the TString with a TString and returns true if contents are unequal
	* Parameters: TString& s - the string to compare
	* Returns: bool - result of comparison
	*/
	bool operator!=(TString& s);
	/*
	* Method: TString::operator!=
	* Purpose: Conpares the TString with a TString and returns true if contents are unequal
	* Parameters: TString* s - the string to compare
	* Returns: bool - result of comparison
	*/
	bool operator!=(TString* s);
	/*
	* Method: TString::operator!=
	* Purpose: Conpares the TString with a wide string and returns true if contents are unequal
	* Parameters: WCHAR* s - the string to compare
	* Returns: bool - result of comparison
	*/
	bool operator!=(WCHAR* s);


	/*
	* Method: TString::GetAnaGameType
	* Purpose: Retrieves the Class type for the AnaGame Virtual Machine
	* Parameters: void
	* Returns: UCHAR* - The AnaGAme type ID
	*/
	virtual UCHAR* GetAnaGameType() override;

	WCHAR operator[](UINT loc)const;


	/**
	 * Method: TString::GetSize
	 * Purpose: Retrieves the size of the string
	 * Parameters: void
	 * Returns: UINT - the current size of the string
	 * 
	 * Attributes: const
	 */
	UINT GetSize() const;
	/**
	 * Method: TString::GetAt
	 * Purpose: Retrieves the character at the provided index
	 * Parameters: UINT c - the index of the character
	 * Returns: WCHAR - the character at the index, '\0' if index is out of bounds
	 * 
	 * Attributes: const
	 */
	WCHAR GetAt(UINT c)const;

	// Relics from MFC CString that we now hve to implement ourselves


	/**
	 * Method: TString::AppendFormat
	 * Purpose: Appends the provided format to this string
	 * Parameters: const WCHAR* format - the template
	 *				... - the series of variables to add
	 * Returns: void
	 */
	void AppendFormat(const WCHAR* format, ...);
	/**
	 * Method: TString::AppendFormat
	 * Purpose: Appends the provided format to this string
	 * Parameters: const TString format - the template
	 *				... - the series of variables to add
	 * Returns: void
	 */
	void AppendFormat(const TString format, ...);
	/**
	 * Method: TString::Format
	 * Purpose: Sets this string to the provided format
	 * Parameters: const WCHAR* format - the template
	 *				... - the series of variables to add
	 * Returns: void
	 */
	void Format(const WCHAR* format, ...);
	/**
	 * Method: TString::Format
	 * Purpose: Sets this string to the provided format
	 * Parameters: const TString format - the template
	 *				... - the series of variables to add
	 * Returns: void
	 */
	void Format(const TString format, ...);
	/**
	 * Method: TString::AppendChar
	 * Purpose: Appends the provided character to this string
	 * Parameters: WCHAR ch - the character to append
	 * Returns: void
	 */
	void AppendChar(const WCHAR ch);
	/**
	 * Method: TString::Append
	 * Purpose: Appends the provided string to this string
	 * Parameters: const TString& app - the string to append
	 * Returns: void
	 */
	void Append(const TString&);

	//static TString GetFormattedString(const TString& format, va_list& data);


	/**
	 * Method: TString::Compare
	 * Purpose: Compares this string with a provided string
	 * Parameters: const TString& other - the string to compare this string to
	 * Returns: int - 0 if they are the same
	 * 
	 * Attributes: const
	 */
	int Compare(const TString& other)const ;
	/**
	 * Method: TString::Compare
	 * Purpose: Compares this string with a provided raw string
	 * Parameters: const WCHAR* other - the string to compare this string to
	 * Returns: int - 0 if they are the same
	 * 
	 * Attributes: const
	 */
	int Compare(const WCHAR* other)const;
	/**
	 * Method: TString::CompareNoCase
	 * Purpose: Compares this string with a provided string, ignoring case
	 * Parameters: const TString& other - the string to compare this string to
	 * Returns: int - 0 if they are the same
	 */
	int CompareNoCase(const TString& other) ;
	/**
	 * static Method: TString::Compare
	 * Purpose: Compares two strings for equality
	 * Parameters: const TString& str1 - the main string to compare
	 *				const TString& str2 - the second string to compare to
	 * Returns: int - 0 if they are the same
	 */
	static int Compare(const TString& str1, const TString& str2);



	/**
	 * Method: TString::Delete
	 * Purpose: Deletes a section of the string in -place
	 * Parameters: int index - the index of the first character to remove
	 *				int count - the number of characters to remove
	 * Returns: int - the new size of the string
	 */
	int Delete(int index, int count = 1);
	/**
	 * Method: TString::GetDelete
	 * Purpose: Retrieves a TString with a section deleted
	 * Parameters: int& ret - the size of the new string
	 *				int index - the index of the first character to remove
	 *				int count - the number of characters to remove
	 * Returns: TString::the String with the Delete operation applied
	 */
	TString GetDelete(int& ret, int index, int count = 1);

	/**
	 * Method: TString::StartsWith
	 * Purpose: deduces whether the String starts with a given sequence
	 * Parameters: const TString& seq - the sequence to check
	 *				bool ignoreCase - whether to ignore case when doing the analysis (false by default)
	 *				bool whitespace - if true, only return true if there is whitespace at the character after 'seq'
	 * Returns: bool
	 * 
	 * Attributes: const
	 * 
	 * Note: Will return false if seq is longer than 'this' string
	 */
	bool StartsWith(const TString&  seq, bool ignoreCase = false, bool whitespace = false) const;


	/**
	 * Method: TString::EndsWith
	 * Purpose: deduces whether the String ends with a given sequence
	 * Parameters: const TString& seq - the sequence to check
	 *				bool ignoreCase - whether to ignore case when doing the analysis (false by default)
	 * Returns: bool
	 *
	 * Note: Will return false if seq is longer than 'this' string
	 */
	bool EndsWith(const TString& seq, bool ignoreCase = false);

	/**
	 * Method: TString::Find
	 * Purpose: Finds the last instance of the specified string
	 * Parameters: const TString& sub - the string to search for
	 *				int start - the index to begin the search from
	 *				bool ignoreEscape - whether to ignore the presence of an escape character infront of a possible hit
	 * Returns: int - the index of the string found
	 * 
	 * Attributes: const
	 */
	int Find(const TString& sub, int start = 0, bool ignoreEscape = true) const;
	/**
	 * Method: TString::Find
	 * Purpose: Finds the first instance of the specified character
	 * Parameters: WCHAR sub - the character to search for
	 *				int start - the index to begin the search from
	 *				bool ignoreEscape - whether to ignore the presence of an escape character infront of a possible hit
	 * Returns: int - the index of the character found
	 * 
	 * Attributes: const
	 */
	int Find(WCHAR sub, int start = 0, bool ignoreEscape = true)const;
	/**
	 * Method: TString::FindOneOf
	 * Purpose: Searches for one of the specified characters
	 * Parameters: const TString& chars -  the list of characters to search for
	 *				int start - the index to begin the search from
	 * Returns: int - the index of the character found
	 * 
	 * Attributes: const
	 */
	int FindOneOf(const TString& chars, int start = 0)const;


	/**
	 * Method: TString::FindLast
	 * Purpose: Finds the last instance of the specified string
	 * Parameters: const TString& sub - the string to search for
	 *				int start - the index to begin the search from (searches backwards)
	 * Returns: int - the index of the string found
	 * 
	 * Attributes: const
	 */
	int FindLast(const TString& sub, int start = -1) const;
	/**
	 * Method: TString::FindLast
	 * Purpose: Finds the last instance of the specified character
	 * Parameters: WCHAR sub - the character to search for
	 *				int start - the index to begin the search from (searches backwards)
	 * Returns: int - the index of the character found
	 * 
	 * Attributes: const
	 */
	int FindLast(WCHAR sub, int start = -1)const ;
	/**
	 * Method: TString::FindLastOneOf
	 * Purpose: Searches backwards for one of the specified characters
	 * Parameters: const TString& chars -  the list of characters to search for
	 *				int start - the index to begin the search from (searches backwards)
	 * Returns: int - the index of the character found
	 * 
	 * Attributes: const
	 */
	int FindLastOneOf(const TString& chars, int start = -1) const;


	/**
	 * Method: TString::SetAsEnvironmentVariable
	 * Purpose:
	 * Parameters: TString& var - the name of the Enviroment variable to set this string to
	 * Returns: bool - whether the operation was successful or not
	 */
	bool SetAsEnvironmentVariable(TString& var);

	/**
	 * Method: TString::CountFinds
	 * Purpose: Counts the number of times the provided string appears in this string
	 * Parameters: const TString& query - the string to search for
	 * Returns: UINT - the number of times the query string appears in this string
	 * 
	 * Attributes: const
	 */
	UINT CountFinds(const TString& query) const;

	/**
	 * Method: TString::CountFinds
	 * Purpose: Counts the number of times the provided character appears in this string
	 * Parameters: WCHAR ch - the string to search for
	 * Returns: UINT - the number of times the query string appears in this string
	 * 
	 * Attributes: const
	 */
	UINT CountFinds(WCHAR ch) const;

	/**
	 * Method: TString::CountOneOfFinds
	 * Purpose: Counts the number of times one of the characters in the provided string appears in this string
	 * Parameters: const TString& query - the collection of characters to search for
	 * Returns: UINT - the number of times the query string appears in this string
	 * 
	 * Attributes: const
	 */
	UINT CountOneOfFinds(const TString& query) const;

	/**
	 * Method: TString::Insert
	 * Purpose: Inserts a sub-string in-place
	 * Parameters: int index - the index to insert the subStr at
	 *				TString& subStr - the string to insert
	 * Returns: int - the size of the new string
	 */
	int Insert(int index, const TString& subStr);
	/**
	 * Method: TString::GetInsert
	 * Purpose: Retrieves a String with a another string inserted
	 * Parameters: int& ret - reference to the size of the string
	 *				int index - the index to insert the character at
	 *				TString& subStr - the string to insert
	 * Returns: TString::The copy of the string with the parameter string inserted
	 */
	TString GetInsert(int& ret, int index, TString& subStr);
	/**
	 * Method: TString::Insert
	 * Purpose: Inserts a character in-place
	 * Parameters: int index - the index to insert the character at
	 *				WCHAR ch - the character to insert
	 * Returns: int - the size of the new string
	 */
	int Insert(int index, WCHAR ch);
	/**
	 * Method: TString::GetInsert
	 * Purpose: Retrieves a String with a character inserted
	 * Parameters: int& ret - reference to the size of the string
	 *				int index - the index to insert the character at
	 *				WCHAR ch - the character to insert
	 * Returns: TString::The copy of the string with the character inserted
	 */
	TString GetInsert(int& ret, int index, WCHAR ch);



	/**
	 * Method: TString::SetLower
	 * Purpose: Sets this string to have all lowercase in-place
	 * Parameters: void
	 * Returns: void
	 */
	void SetLower();
	/**
	 * Method: TString::GetLower
	 * Purpose: Retrieves a version of the String with all lowercase
	 * Parameters: void
	 * Returns: TString::the lowercase version of the String
	 * 
	 * Attributes: const
	 */
	TString GetLower()const;
	/**
	 * Method: TString::SetUpper
	 * Purpose: Sets this string to have all caps in-place
	 * Parameters: void
	 * Returns: void
	 */
	void SetUpper();
	/**
	 * Method: TString::GetUpper
	 * Purpose: Retrieves a version of the String with all caps
	 * Parameters: void
	 * Returns: TString::the Uppercase version of the String
	 * 
	 * Attributes: const
	 */
	TString GetUpper()const;



	/**
	 * Method: TString::SetReverse
	 * Purpose: Reverses the contents of the string in-place
	 * Parameters: void
	 * Returns: void
	 */
	void SetReverse();
	/**
	 * Method: TString::GetReverse
	 * Purpose: Retrieves a TString that has the contents reversed
	 * Parameters: void
	 * Returns: TString::the copy with the characters reversed
	 */
	TString GetReverse();


	/**
	 * Method: TString::Remove
	 * Purpose: Removes the character from the TSTring in-place
	 * Parameters: WCHAR c - the character to remove
	 * Returns: int - The number of times the WCHAR was found in the string
	 */
	int Remove(WCHAR c);
	/**
	 * Method: TString::GetRemove
	 * Purpose: Returns a TString with a given character removed
	 * Parameters: int& ret - The number of times the WCHAR was found in the string
	 *				WCHAR c - the character to remove
	 * Returns: TString::copy with the specified character removed
	 */
	TString GetRemove(int& ret, WCHAR c);



	/**
	 * Method: TString::Replace
	 * Purpose: Applies the Replace operation via TStrings as parameters
	 * Parameters: const TString& oldStr - the String to replace
	 *				const TString& newStr - the String to replace the old string with
	 * Returns: int - the number of instances where the replacement operaiton was applied
	 */
	int Replace(const TString& oldStr, const TString& newStr);
	/**
	 * Method: TString::GetReplace
	 * Purpose: Returns a copy of the TString with the old String replaced by the new one
	 * Parameters: int& ret - reference of the replacemnt counter
	 *				const TString& oldStr - the String to replace
	 *				const TString& newStr - the String to replace the old string with
	 * Returns: TString::The Copy with the Replace operation applied
	 */
	TString GetReplace(int& ret, const TString& oldStr, const TString& newStr);
	/**
	 * Method: TString::Replace
	 * Purpose: In-place character replacement operation
	 * Parameters: WCHAR& oldStr - the character to replace
	 *				 WCHAR& newStr - the character to replace the old one with
	 * Returns: The number of characters in the string replaced
	 */
	int Replace(WCHAR& oldStr, WCHAR& newStr);
	/**
	 * Method: TString::GetReplace
	 * Purpose: Returns a copy of the TString with the old character replaced by the new one
	 * Parameters: int& ret - reference to the return value, see "Returns:" for the Replace method
	 *				 WCHAR& oldStr - the character to replace
	 *				 WCHAR& newStr - the character to replace the old one with
	 * Returns: TString::copy of the string with the replace operation applied
	 */
	TString GetReplace(int& ret, WCHAR& oldStr, WCHAR& newStr);


	/**
	 * Method: TString::Tokenize
	 * Purpose: Allows the Traditional Tokenization routine to be performed in the TString
	 * Parameters: TString& tokens - characters to split by
	 *				 int& start - the location to begin at
	 * Returns:
	 * 
	 * Attributes: const
	 */
	TString Tokenize(TString& tokens, int& start) const;


	/*
	* Method: TString::Trim
	* Purpose: Removes Whitespace on both sides
	* Parameters: void
	* Returns: void
	*/
	void Trim();

	/**
	 * Method: TString::GetTrim
	 * Purpose: Retrieves acopy of the TString with whitespace trimmed. It does not alter the original String
	 * Parameters: void
	 * Returns: TString::Trimmed copy of the String
	 * 
	 * Attributes: const
	 */
	TString GetTrim() const;

	/**
	 * Method: TString::TrimRight
	 * Purpose: Performs an in-place trimming of whitespace towards the end
	 * Parameters: void
	 * Returns: void
	 */
	void TrimRight();

	/**
	 * Method: TString::GetTrimRight
	 * Purpose: Retrieves a version of the string with no whitespace on the end
	 * Parameters: void
	 * Returns: TString::the String with the TrimRight operation performed
	 */
	TString GetTrimRight();

	/**
	 * Method: TString::TrimLeft
	 * Purpose: Performs an in-place trimming of whitespace at the beginning
	 * Parameters: void
	 * Returns: void
	 */
	void TrimLeft();

	/**
	 * Method: TString::GetTrimLeft
	 * Purpose: Retrieves a version of the string with no whitespace towards the beginning
	 * Parameters: void
	 * Returns: TString::the String with the TrimLeft  operation performed
	 */
	TString GetTrimLeft();


	/**
	 * Method: TString::Empty
	 * Purpose: Dumps the contents of the string so it is empty
	 * Parameters: void
	 * Returns: void
	 */
	void Empty();

	/**
	 * Method: TString::IsEmpty
	 * Purpose: Reports whether the string is empty
	 * Parameters: void
	 * Returns: bool - whether the string is empty or not
	 */
	bool IsEmpty();


	/**
	 * Method: TString::GetRegString
	 * Purpose: Retrieves a version of the string in ASCII, using the std::string as the return type
	 * Parameters: void
	 * Returns: std::string - the TString with ASCII content
	 */
	std::string GetRegString();

private:
	UINT size;			// Note: these values focus on the number of WCHARs
	UINT capacity;
	WCHAR* string;
};

/*
* Function: convertToNumber
* Purpose: Converts a character into a number
* Parameters: TCHAR c - the character to convert
*			int* i - the new number
* Returns: bool - whether character was a number
*/
bool convertToNumber(TCHAR c, int* i);

/*
* Function: convertToNumber
* Purpose: Converts a character into a number, allowing for hew values
* Parameters: TCHAR c - the character to convert
*			int* i - the new number
* Returns: bool - whether character was a number
*/
bool convertToNumberHex(TCHAR c, UINT& i);

/*
* Function: convertHueToRGB
* Purpose: Converts an hsv value to a comparble RGB format
* Parameters: float p - the p of the new color 
*			float q - the q of the new color
*			int hue - the hue of the color
* Returns: float - the color in an RGB channel
*/
float ConvertHueToRGB(float p, float q, int hue);

/*
* Function: ReturnWCharType
* Purpose: Returns the WCHAR representation of the char
* Parameters: char c - the chaacter to convert
* Returns: WCHAR - the wide version of the character
*/
WCHAR ReturnWCharType(char c);

/**
 * Function: IndexComesFirst
 * Purpose: Reports whether a given Index "comes first" in a string
 * Parameters: int focusIndex - the index to see if it "comes first"
 *				int checkIndex - the index to check the focus index against
 * Returns: bool - whether the focus index comes first - meaning it is not -1 and the check Index is -1 or comes after the focus index
 */
bool IndexComesFirst(int focusIndex, int checkIndex);
