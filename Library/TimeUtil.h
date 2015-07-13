#include <ctime>
#include <stdio.h>
#include <cstdlib> 
#include <string>

#pragma once
using namespace std;
class TimeUtil
{
public:
	TimeUtil();
	~TimeUtil();
	void TimeToString(time_t time1, char *szTime);
	time_t StringToTime(char * szTime);
	string AddMonth(time_t &tTime);
};

