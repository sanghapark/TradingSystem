// tstringstream.h

#ifndef _TSTRINGSTREAM_H
#define _TSTRINGSTREAM_H

#include <sstream>

using namespace std;

// UnicodeÀÌ¸é	tstringstream -> wstringstream
// MBCD			tstringstream -> string
#ifdef _UNICODE
typedef wstringstream tstringstream;
#else
typedef stringstream tstringstream;
#endif

#endif