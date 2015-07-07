
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h> 
#include <iostream>
#include "User.h"
class DBUtil
{
public:
	DBUtil();
	~DBUtil();
	User ReadUser(string strUserName, string strUserPWD);
	
};

