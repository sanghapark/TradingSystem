// LoginTime.h

#ifndef _LOGIN_TIME_H
#define _LOGIN_TIME_H

#include "DataTypeDefinition.h"


class LoginTime{
	public:
		LoginTime();
		LoginTime(const tstring& timeStart, const tstring& timeEnd, bool checker);
		LoginTime(const LoginTime& source);
		~LoginTime();





		bool IsEqual(const LoginTime& other);
		bool IsNotEqual(const LoginTime& other);

		LoginTime& operator=(const LoginTime& source);
		bool operator==(const LoginTime& other);
		bool operator!=(const LoginTime& other);
		
		tstring& GetTimeStart() const;
		tstring& GetTimeEnd() const;
		bool GetChecker() const;

	private:
		tstring timeStart;
		tstring timeEnd;
		bool checker;
};


inline tstring& LoginTime::GetTimeStart() const{
	return const_cast<tstring&>(this->timeStart);
}

inline tstring& LoginTime::GetTimeEnd() const{
	return const_cast<tstring&>(this->timeEnd);
}

inline bool LoginTime::GetChecker() const{
	return this->checker;
}



#endif