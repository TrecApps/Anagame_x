#ifndef ANAGAME_TYPES
#define ANAGAME_TYPES

typedef unsigned char UCHAR;
typedef unsigned int UINT;
typedef unsigned short USHORT;
typedef wchar_t WCHAR;
typedef char TCHAR;

// Note: this structure will eventually have to be renamed and possibly replaced to ensure compatibility with the Linux-library for graphics
typedef struct D2D1_COLOR_F {
	float r,g,b,a;
} D2D1_COLOR_F;



#endif
