#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
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
	bool DisplayAllBook();
	bool QueryBook(string strBookName);
	bool DeleteBook(int nBookId);
	TimeUtil m_timeUtil;
	DBUtil m_dbUtil;
};

