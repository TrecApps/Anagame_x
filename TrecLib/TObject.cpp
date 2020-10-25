#include "TObject.h"
#include "TString.h"

UCHAR TObjectType[] = { 1, 0b10000000 };

WCHAR str_true[] = L"true";
WCHAR str_false[] = L"false";


/*
* Method: TObject::TObject
* Purpose: Default constructor for the TObject
* Parameters: void
* Returns: void
*/
TObject::TObject()
{
	//sys_Type = new LPCTSTR((LPCTSTR)"SYS_TOBJECT");
}

/*
* Method: TObject::~TObject
* Purpose: Destructor
* Parameters: void
* Returns: void
*/
TObject::~TObject()
{

}

/*
* Method: TObject::GetAnaGameType
* Purpose: Retrieves the AnaGame type
* Parameters: void
* Returns: UCHAR* - the AnaGame type represenation 
*
* Note: deprecated
*/
UCHAR * TObject::GetAnaGameType()
{
	return TObjectType;
}

/**
 * Method: TObject::getVariableValueStr
 * Purpose: Returns the String value of a TObjects given variable, meant for databinding
 * Parameters: TString& varName - the name of the variable to seek
 * Returns: TString - the variable value in String form, or an empty string if variable does not exist
 */
TString TObject::getVariableValueStr(const TString & varName)
{
	return TString();
}

/**
 * Method: TObject::toString
 * Purpose: Returns a string representation of this object
 * Parameters: void
 * Returns: TString - repreetnation of this object
 */
TString TObject::toString()
{
	return TString();
}

/**
 * Method: TObject::GetType
 * Purpose: Returns a String Representation of the object
 * Parameters: void
 * Returns: TString - representation of the object type
 *
 * Note: This method is provided to allow interpretors to allow scripts to access methods of Anagame Objects.
 *   subclasses should report their type first, then the parent clss type and seperate it with a SemiColon
 */
TString TObject::GetType()
{
	return TString(L"TObject");
}

TObject* TObject::ProcessPointer(TObject* obj)
{
	return obj;
}

TObject* TObject::ProcessPointer(void* obj)
{
	return nullptr;
}

TObject* TObject::ProcessPointer(int* obj)
{
	return nullptr;
}

TObject* TObject::ProcessPointer(float* obj)
{
	return nullptr;
}

/*
* Function: boolToString 
* Purpose: returns string representations of the bool
* Parameters: bool val -  the bool to convert
* Returns: WCHAR* string representations
*/
WCHAR* boolToString(bool val)
{
	if (val)
		return str_true;
	else
		return str_false;
}
