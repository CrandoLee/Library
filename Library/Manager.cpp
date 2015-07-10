#include "Manager.h"

Manager::Manager()
{
}


Manager::~Manager()
{
}


void Manager::ShowMenu()
{
	system("cls");
	cout << "==========================欢迎使用图书馆后台管理系统：==========================" << endl;
	cout << "                              1.新书录入" << endl;
	cout << "                              2.图书查询" << endl;
	cout << "                              3.图书查询" << endl;
	cout << "                              4.查看仓库" << endl;
	cout << "                              5.借阅记录" << endl;
	cout << "                              6.借阅统计" << endl;
	cout << "                              7.新增用户" << endl;
	cout << "                              8.查询用户" << endl;
	cout << "                              0.退出登录" << endl;
}

bool Manager::AddBook()
{
	int id;
	string bookName;
	string author;
	string isbn;
	string pub;
	int total;
	char szTime[32] = {0};
	struct tm *ptr;
	time_t lt;
	lt = time(NULL);
	m_timeUtil.TimeToString(lt, szTime);

	cout << "你选择的是新增图书功能，请依次输入图书信息" << endl;
	cout << "图书名称 作者 ISBN 出版社 总册数" << endl;
	cin >> bookName;
	cin >> author;
	cin >> isbn;
	cin >> pub;
	cin >> total;

	Book book;
	book.SetBookName(bookName);
	book.SetAuthor(author);
	book.SetISBN(isbn);
	book.SetPub(pub);
	book.SetTotalNum(total);
	book.SetLeftNum(0);
	book.SetInDate(szTime);

	m_dbUtil.OpenDB();
	m_dbUtil.addBook(book);
	return true;
}

//展示所有书籍
bool Manager::DisplayBook()
{
	return true;
}