#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#include <mysql.h> 
#include <iostream>
#include <vector>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
#include "BorrowRecord.h"
#pragma once
class DBUtil
{
public:
	DBUtil();
	~DBUtil();
	bool OpenDB();
	bool CloseDB();
	User ReadUser(string strUserName, string strUserPWD);
	bool AddBook(Book book);
	bool SelectAllBook(vector<Book> &books);
	bool SelectBookByName(string strBookName, vector<Book> &books);
	bool SelectBookById(int nBookId, Book &book);
	bool DeleteBookById(int nBookId);
	bool AddBorrowRecord(BorrowRecord borrowRecord);
	bool FinishBorrowRecord(int nRecordId, int nBookId);
	bool SelectAllBorrowRecord(vector<BorrowRecord> &borrowRecords);
	bool SelectBorrowRecordByUserId(vector<BorrowRecord> &borrowRecords, int nUserId, int nType);
	User SelectUserById(int nUserId);
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

