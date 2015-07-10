#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <time.h>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
#include "DBUtil.h"
using namespace std;
#pragma once
class Manager:public User
{
public:
	Manager();
	~Manager();
	void ShowMenu();
	bool AddBook();
	bool DisplayBook();
	TimeUtil m_timeUtil;
	DBUtil m_dbUtil;
};

