#include <new>
#include <memory>

#include "AnagameDef.h"


extern UCHAR TArrayType[];
extern UCHAR TDataArrayType[];
extern UCHAR TMapType[];

class TString;

/*
* Class TObject
* Serves as the base object for the AnaGame platform
*/
class TObject 
{
public:
	TObject();
	virtual ~TObject();

	virtual UCHAR* GetAnaGameType();
	virtual TString getVariableValueStr(const TString& varName);
	virtual TString toString();

protected:
	
};
