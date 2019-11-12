#pragma once
#include "TDataArray.h"
#include "TObject.h"
#include <string>
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
	TString();
	~TString();
	TString(const TString*);
	TString(const char*);
	TString(const WCHAR*);
	TString(const TString& c);
	TString(std::string& str);
	TString(WCHAR c);

	short ConvertToInt(int*);
	short ConvertToDouble(double*);
	short ConvertToLong(long long*);
	short ConvertToFloat(float*);

	TrecPointer<typename TDataArray<TString>> split(TString, bool checkBackSlash = false);
	WCHAR* GetBufferCopy()const ;

	const WCHAR* GetConstantBuffer() const;

	TString SubString(UINT beginningIndex, int endIndex = -1);

	//bool ConvertToColor(D2D1_COLOR_F& color, ColorFormat& cf);

	int FindOutOfQuotes(TString& subString, int start = 0);

	// Set Methods, to be used in place of Assignment operators to avoid C26444 Warnings
	void Set(const TString& s);
	void Set(const TString* s);
	void Set(const WCHAR* w);
	void Set(const WCHAR w);


	TString operator=(const TString&);
	TString operator=(const TString* s);
	TString operator=(const WCHAR* w);
	TString operator=(const WCHAR w);
	TString operator+(const TString&);
	TString operator+(const TString*);
	TString operator+(const WCHAR*);
	TString operator+(const WCHAR w);
	TString operator+=(const TString&);
	TString operator+=(const TString*);
	TString operator+=(const WCHAR*);
	TString operator+=(const WCHAR w);

	//void operator+=(TString*);
	//void operator

	bool operator==(TString& s);
	bool operator==(TString* s);
	bool operator==(WCHAR* s);

	bool operator!=(TString& s);
	bool operator!=(TString* s);
	bool operator!=(WCHAR* s);

	virtual UCHAR* GetAnaGameType() override;

	WCHAR operator[](UINT loc)const;

	UINT GetSize() const;
	WCHAR GetAt(UINT c)const;

	// Relics from MFC CString that we now hve to implement ourselves
	void AppendFormat(const WCHAR* format, ...);
	void AppendFormat(const TString format, ...);
	void Format(const WCHAR* format, ...);
	void Format(const TString format, ...);
	void AppendChar(const WCHAR ch);
	void Append(const TString&);

	static TString GetFormattedString(const TString& format, va_list& data);

	int Compare(const TString& other)const ;
	int Compare(const WCHAR* other)const;
	int CompareNoCase(const TString& other) ;
	static int Compare(const TString& str1, const TString& str2);

	int Delete(int index, int count = 1);
	TString GetDelete(int& ret, int index, int count = 1);

	int Find(const TString& sub, int start = 0);
	int Find(WCHAR sub, int start = 0);
	int FindOneOf(const TString& chars, int start = 0);

	int FindLast(const TString& sub, int start = -1);
	int FindLast(WCHAR sub, int start = -1);
	int FindLastOneOf(const TString& chars, int start = -1);

	bool SetAsEnvironmentVariable(TString& var);

	int Insert(int index, const TString& subStr);
	TString GetInsert(int& ret, int index, TString& subStr);
	int Insert(int index, WCHAR ch);
	TString GetInsert(int& ret, int index, WCHAR ch);

	void SetLower();
	TString GetLower();
	void SetUpper();
	TString GetUpper();

	void SetReverse();
	TString GetReverse();

	int Remove(WCHAR c);
	TString GetRemove(int& ret, WCHAR c);

	int Replace(const TString& oldStr, const TString& newStr);
	TString GetReplace(int& ret, const TString& oldStr, const TString& newStr);
	int Replace(WCHAR& oldStr, WCHAR& newStr);
	TString GetReplace(int& ret, WCHAR& oldStr, WCHAR& newStr);

	TString Tokenize(TString& tokens, int& start);

	void Trim();
	TString GetTrim() const;
	void TrimRight();
	TString GetTrimRight();
	void TrimLeft();
	TString GetTrimLeft();

	void Empty();
	bool IsEmpty();

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
