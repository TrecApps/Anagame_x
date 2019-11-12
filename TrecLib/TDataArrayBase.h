#pragma once
#include "TObject.h"
class _TREC_LIB_DLL TDataArrayBase :
	public TObject
{
public:
	TDataArrayBase(const UINT s, const UINT c);
	TDataArrayBase(const TDataArrayBase&);
	~TDataArrayBase();

	virtual UCHAR* GetAnaGameType() override;
	UINT Size()const;
	UINT Capacity()const;
	virtual TObject* GetObjectAt(UINT loc) = 0;
protected:
	UINT size, capacity;
};

