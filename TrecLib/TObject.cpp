#include "TObject.h"
#include "TString.h"

UCHAR TObjectType[] = { 1, 0b10000000 };

WCHAR str_true[] = L"true";
WCHAR str_false[] = L"false";


/*
* Method: (TObject) (Constructor)
* Purpose: Default constructor for the TObject
* Parameters: void
* Returns: void
*/
TObject::TObject()
{
	//sys_Type = new LPCTSTR((LPCTSTR)"SYS_TOBJECT");
}

/*
* Method: (TObject) (Destructor)
* Purpose: Cleans up TObject
* Parameters: void
* Returns: void
*/
TObject::~TObject()
{

}

/*
* Method: TObject - GetAnaGameType
* Purpose: Retrieves the AnaGame type
* Parameters: void
* Returns: UCHAR* - the AnaGame type represenation 
*/
UCHAR * TObject::GetAnaGameType()
{
	return TObjectType;
}

/**
 * Method: TObject - getVariableValueStr
 * Purpose: Returns the String value of a TObjects given variable, meant for databinding
 * Parameters: TString& varName - the name of the variable to seek
 * Returns: TString - the variable value in String form, or an empty string if variable does not exist
 */
TString TObject::getVariableValueStr(const TString & varName)
{
	return TString();
}

TString TObject::toString()
{
	return TString();
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
