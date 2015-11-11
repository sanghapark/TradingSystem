// tstring.h

#ifndef _TSTRING_H
#define _TSTRING_H

#include <string>

using namespace std;


// UnicodeÀÌ¸é	tstring -> wstring
// MBCD			tstring -> string
#ifdef _UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif




#endif