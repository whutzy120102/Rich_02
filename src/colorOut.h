
#ifndef _COLOR_OUT_H_
#define _COLOR_OUT_H_


#include <windows.h>
#include <iostream>
static void  SetConsoleColor(WORD wAttribute)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, wAttribute);
}

inline std::ostream&  yellowcolor(std::ostream& ostr)
{
	SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return ostr;
}

inline std::ostream&  greencolor(std::ostream& ostr)
{
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return ostr;
}

inline std::ostream&  bluecolor(std::ostream& ostr)
{
	SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	return ostr;
}

inline std::ostream&  redcolor(std::ostream& ostr)
{
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	return ostr;
}

inline std::ostream&  lredcolor(std::ostream& ostr)
{
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return ostr;
}
//std::cout << greencolor << "hello " << redcolor << " world!";

#endif