#include "DBUtil.h"


DBUtil::DBUtil()
{
	szUsername = "root";
	szPswd = "ROOT";
	szHost = "localhost";
	szDatabase = "library";
	nPort = 3306;
	isOpen = false;
}


DBUtil::~DBUtil()
{
	CloseDB();
}

//打开数据库
bool DBUtil::OpenDB()
{
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, szHost.c_str(), szUsername.c_str(), szPswd.c_str(), szDatabase.c_str(), nPort, NULL, 0))
	{
		isOpen = true;
		return true;
	}
	return false;
}

//关闭数据库
bool DBUtil::CloseDB()
{
	mysql_close(&myCont);//断开连接
	return true;
}



//根据用户名和密码获得用户信息
User DBUtil::ReadUser(string strUserName, string strUserPWD)
{
	User user;
	char column[32][32];
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "select * from user where name='" + strUserName + "' and password='" + strUserPWD + "'";
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result->row_count > 0)
			{
				int i, j;
				//cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;
				for (i = 0; fd = mysql_fetch_field(result); i++)//获取列名
				{
					strcpy_s(column[i], fd->name);
				}
				j = mysql_num_fields(result);

				if (j > 0)
				{
					sql_row = mysql_fetch_row(result);
					user.m_nID = atoi(sql_row[0]);
					user.m_strName = sql_row[1];
					user.m_nRole = atoi(sql_row[3]);
				}
			}
			else
			{
				user.m_nID = -1;
				return user;
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//释放结果资源
	}
	return user;
}

//新增图书
bool DBUtil::AddBook(Book book)
{
	string sql = "";
	char szTotal[16];
	char szLeftNum[16];
	sprintf(szTotal, "%d", book.GetTotalNum());
	sprintf(szLeftNum, "%d", book.GetTotalNum());

	if (isOpen)
	{
		//获得时间
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "insert into book values(null,'" + book.GetBookName() + "','" + book.GetAuthor() + "','" + book.GetISBN() + "','" + book.GetPub() + "','" + book.GetInDate() + "', " + szTotal + ", " + szLeftNum + ")";
		mysql_query(&myCont, sql.c_str());
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	cin.get();
	cin.get();
	return false;

}

//搜索所有图书
bool DBUtil::SelectAllBook(vector<Book> &books)
{
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "select * from book";
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					Book book;
					book.SetBookID(atoi(sql_row[0]));
					book.SetBookName(sql_row[1]);
					book.SetAuthor(sql_row[2]);
					book.SetISBN(sql_row[3]);
					book.SetPub(sql_row[4]);
					book.SetInDate(sql_row[5]);
					book.SetTotalNum(atoi(sql_row[6]));
					book.SetLeftNum(atoi(sql_row[7]));
					books.push_back(book);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//释放结果资源
	}

	return true;
}

//根据书名查询书籍
bool DBUtil::SelectBookByName(string strBookName, vector<Book> &books)
{
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "select * from book where bookname like '%" + strBookName + "%'";
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					Book book;
					book.SetBookID(atoi(sql_row[0]));
					book.SetBookName(sql_row[1]);
					book.SetAuthor(sql_row[2]);
					book.SetISBN(sql_row[3]);
					book.SetPub(sql_row[4]);
					book.SetInDate(sql_row[5]);
					book.SetTotalNum(atoi(sql_row[6]));
					book.SetLeftNum(atoi(sql_row[7]));
					books.push_back(book);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//释放结果资源
	}
	return true;
}

//根据图书ID查询书籍
bool DBUtil::SelectBookById(int nBookId, Book &book)
{
	int res;
	string sql;
	char szBookId[5] = {0};
	sprintf(szBookId, "%d", nBookId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "select * from book where id=";
		sql += szBookId;
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					book.SetBookID(atoi(sql_row[0]));
					book.SetBookName(sql_row[1]);
					book.SetAuthor(sql_row[2]);
					book.SetISBN(sql_row[3]);
					book.SetPub(sql_row[4]);
					book.SetInDate(sql_row[5]);
					book.SetTotalNum(atoi(sql_row[6]));
					book.SetLeftNum(atoi(sql_row[7]));
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//释放结果资源
	}
	return true;
}

//根据ID删除图书
bool DBUtil::DeleteBookById(int nBookId)
{
	int res;
	string sql;
	char szBookId[5] = {0};
	sprintf(szBookId, "%d", nBookId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "delete from book where id=" ;
		sql += szBookId;
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}

	return true;
}

//新增借阅记录
bool DBUtil::AddBorrowRecord(BorrowRecord borrowRecord)
{
	string sql = "";
	char szBookId[16];
	char szUserId[16];
	sprintf(szBookId, "%d", borrowRecord.m_nBookId);
	sprintf(szUserId, "%d", borrowRecord.m_nUserId);
	if (isOpen)
	{
		sql = sql + "insert into borrowrecord values(null," + szBookId + "," + szUserId + ",'" + borrowRecord.m_tBorrowDate + "','" + borrowRecord.m_tShouldReturnDate + "',NULL,0)";
		mysql_query(&myCont, sql.c_str());

		sql = "";

		sql = sql + "update book set book.left=book.left-1 where id = " + szBookId;
		mysql_query(&myCont, sql.c_str());
		cout << "借阅成功!" << endl;
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	return false;

}


//根据用户ID获得用户信息
User DBUtil::SelectUserById(int nUserId)
{
	int res;
	string sql;
	User user;
	char szUserId[5] = { 0 };
	sprintf(szUserId, "%d", nUserId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "select * from user where id=";
		sql += szUserId;
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					user.m_nID = nUserId;
					user.m_strName = sql_row[1];
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//释放结果资源
	}
	return user;
}

//查询所有借阅记录
bool DBUtil::SelectAllBorrowRecord(vector<BorrowRecord> &borrowRecords)
{
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "select * from borrowrecord";
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					BorrowRecord borrowRecord;
					borrowRecord.m_nBorrowId = atoi(sql_row[0]);
					borrowRecord.m_nBookId = atoi(sql_row[1]);
					borrowRecord.m_nUserId = atoi(sql_row[2]);
					borrowRecord.m_tBorrowDate = sql_row[3];
					borrowRecord.m_tShouldReturnDate = sql_row[4];
					borrowRecord.m_tReturnDate = (sql_row[5] == NULL ? "" : sql_row[5]);
					borrowRecord.m_nContinue = atoi(sql_row[6]);
					borrowRecords.push_back(borrowRecord);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//释放结果资源
	}

	return true;
}

//查询某位用户的借阅记录 
bool DBUtil::SelectBorrowRecordByUserId(vector<BorrowRecord> &borrowRecords, int nUserId, int nType)
{
	//nType=1表示选择未归还 nType=2表示选择全部
	int res;
	string sql;
	char szUserId[8] = {0};
	sprintf(szUserId, "%d", nUserId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql = sql + "select * from borrowrecord where userid=" + szUserId;
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					//不等于空表示已经归还
					if (nType == 1)
					{
						if (sql_row[5] != NULL)
						{
							continue;
						}
					}

					BorrowRecord borrowRecord;
					borrowRecord.m_nBorrowId = atoi(sql_row[0]);
					borrowRecord.m_nBookId = atoi(sql_row[1]);
					borrowRecord.m_nUserId = atoi(sql_row[2]);
					borrowRecord.m_tBorrowDate = sql_row[3];
					borrowRecord.m_tShouldReturnDate = sql_row[4];
					borrowRecord.m_tReturnDate = (sql_row[5] == NULL ? "" : sql_row[5]);
					borrowRecord.m_nContinue = atoi(sql_row[6]);
					borrowRecords.push_back(borrowRecord);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//释放结果资源
	}

	return true;
}

//归还书籍
bool DBUtil::FinishBorrowRecord(int nRecordId,int nBookId)
{
	string sql = "";
	char szRecordId[16];
	char szBookId[16];
	sprintf(szRecordId, "%d", nRecordId);
	sprintf(szBookId, "%d", nBookId);
	time_t tTemp = time(NULL);
	char szTime[16] = { 0 };
	timeUtil.TimeToString(tTemp, szTime);
	if (isOpen)
	{
		sql = sql + "update borrowrecord set returndate='" + szTime + "' where id=" + szRecordId;
		mysql_query(&myCont, sql.c_str());

		sql = "";

		sql = sql + "update book set book.left=book.left+1 where id = " + szBookId;
		mysql_query(&myCont, sql.c_str());
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	return true;

}

//增加用户
bool DBUtil::AddUser(User user)
{
	string sql = "";
	char szRoleType[16];
	sprintf(szRoleType, "%d", user.m_nRole);

	if (isOpen)
	{
		sql += "insert into user values(null,'" + user.m_strName + "','" + user.m_strPassword + "'," + szRoleType + ")";
		mysql_query(&myCont, sql.c_str());
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	return true;
}

//查询所有用户
bool DBUtil::SelectAllUser(vector<User> &users)
{
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "select * from user";
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					User user;
					user.m_nID = atoi(sql_row[0]);
					user.m_strName = sql_row[1];
					user.m_nRole = atoi(sql_row[3]); 
					users.push_back(user);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//释放结果资源
	}
	return true;
}

//续借图书
bool DBUtil::ExtendBorrowRecord(int nRecordId)
{
	string sql = "";
	char szRecordId[16];
	char szBookId[16];
	sprintf(szRecordId, "%d", nRecordId);
	time_t tTemp = time(NULL);
	if (isOpen)
	{
		sql = sql + "update borrowrecord set shouldreturndate='" + timeUtil.AddMonth(tTemp) + "',borrowrecord.continue=borrowrecord.continue+1 where id=" + szRecordId;
		mysql_query(&myCont, sql.c_str());
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	return true;
}

//根据ID查询借阅记录
bool DBUtil::SelectBorrowRecordByRecordId(BorrowRecord &borrowRecord, int nRecordId)
{
	int res;
	string sql;
	char szRecordId[8] = { 0 };
	sprintf(szRecordId, "%d", nRecordId);
	if (isOpen)
	{
		sql = sql + "select * from borrowrecord where id=" + szRecordId;
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				sql_row = mysql_fetch_row(result);
				borrowRecord.m_nBorrowId = atoi(sql_row[0]);
				borrowRecord.m_nBookId = atoi(sql_row[1]);
				borrowRecord.m_nUserId = atoi(sql_row[2]);
				borrowRecord.m_tBorrowDate = sql_row[3];
				borrowRecord.m_tShouldReturnDate = sql_row[4];
				borrowRecord.m_tReturnDate = (sql_row[5] == NULL ? "" : sql_row[5]);
				borrowRecord.m_nContinue = atoi(sql_row[6]);
				
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//释放结果资源
	}

	return true;
}