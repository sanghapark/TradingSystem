// tchar.h
#ifndef _TCHAR_H
#define _TCHAR_H


// UnicodeÀÌ¸é	tchar -> wchar_t
// MBCD			tchar -> char
#ifdef _UNICODE
typedef wchar_t tchar;
#else
typedef char tchar;
#endif


#endif