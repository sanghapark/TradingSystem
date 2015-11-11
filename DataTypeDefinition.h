//DataTypeDefinition.h
#ifndef _DATA_TYPE_DEFINITION_H
#define _DATA_TYPE_DEFINITION_H

#include <string>
#include <sstream>
#include <fstream>

using namespace std;


#ifdef _UNICODE
	#define tchar			wchar_t
	typedef basic_string<wchar_t>            tstring;
	typedef basic_istream<wchar_t>            tistream;
	typedef basic_ostream<wchar_t>            tostream;
	typedef basic_fstream<wchar_t>            tfstream;
	typedef basic_ifstream<wchar_t>            tifstream;
	typedef basic_ofstream<wchar_t>            tofstream;
	typedef basic_stringstream<wchar_t>        tstringstream;
	typedef basic_istringstream<wchar_t>    tistringstream;
	typedef basic_ostringstream<wchar_t>    tostringstream;
#else
	#define tchar			char
	typedef basic_string<char>                tstring;
	typedef basic_istream<char>                tistream;
	typedef basic_ostream<char>                tostream;
	typedef basic_fstream<char>                tfstream;
	typedef basic_ifstream<char>            tifstream;
	typedef basic_ofstream<char>            tofstream;
	typedef basic_stringstream<char>        tstringstream;
	typedef basic_istringstream<char>        tistringstream;
	typedef basic_ostringstream<char>        tostringstream;
#endif


#endif