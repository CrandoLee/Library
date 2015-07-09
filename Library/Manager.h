#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <time.h>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
using namespace std;
#pragma once
class Manager:public User
{
public:
	Manager();
	~Manager();
	void ShowMenu();
	bool AddBook();
	TimeUtil m_timeUtil;
};

