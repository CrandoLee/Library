#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#include <mysql.h> 
#include <iostream>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
#pragma once
class DBUtil
{
public:
	DBUtil();
	~DBUtil();
	bool OpenDB();
	bool CloseDB();
	User ReadUser(string strUserName, string strUserPWD);
	bool addBook(Book book);
public:
	string szUsername;			//用户名
	string szPswd;				//密码
	string szHost;				//主机名
	string szDatabase;			//数据库名
	int nPort;					//端口号  
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	MYSQL_FIELD *fd;
	bool isOpen;
	TimeUtil timeUtil;
};

