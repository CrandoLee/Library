#include <iostream>
#include "User.h"
#include "Manager.h"
#include "DBUtil.h"
#include "Student.h"
#include "Book.h"
using namespace std;

int main()
{
	string strUserName = "";
	string strUserPWD = "";
	bool bIsLogin = false;
	User user;
	cout << "                      请输入用户名：";
	cin >> strUserName;
	cout << endl;
	cout << "                      请输入密码：";
	cin >> strUserPWD;
	cout << endl;
	DBUtil dbUtil;
	dbUtil.OpenDB();
	user = dbUtil.ReadUser(strUserName, strUserPWD);
	if (user.m_nRole == 1)
	{
		Manager manager;
		manager.m_nID = user.m_nRole;
		manager.m_strName = user.m_strName;
		manager.m_nRole = user.m_nRole;
		int command = -1;		//选择命令
		bIsLogin = true;
		string strBookName = "";
		int nBookId = 0;
		while (bIsLogin)
		{
			system("cls");
			manager.ShowMenu();
			cout << "请选择命令：";
			cin >> command;
			switch (command)
			{
			case 1:
				//选择新增图书
				manager.AddBook();			
				break;
			case 2:
				cout << "请输入书名：";
				cin >> strBookName;
				manager.QueryBook(strBookName);
				break;
			case 3:
				cout << "请输入要删除图书的ID" << endl;
				cin >> nBookId;
				manager.DeleteBook(nBookId);
				break;
			case 4:
				manager.DisplayAllBook();
				break;
			case 5:
				manager.DiaplayAllBorrowRecord();
				break;
			case 0:
				//选择退出登录
				bIsLogin = false;
				break;
			default:
				break;
			}
		}
		cout << "您已退出登录，按任意键退出..." << endl;
	}
	else
	{
		Student student;
		student.m_nID = user.m_nRole;
		student.m_strName = user.m_strName;
		student.m_nRole = user.m_nRole;
		int command = -1;		//选择命令
		bIsLogin = true;
		string strBookName = "";
		int nBookId;
		while (bIsLogin)
		{
			system("cls");
			student.ShowMenu();
			cout << "请选择命令：";
			cin >> command;
			switch (command)
			{
			case 1:
				//选择查询图书
				cout << "请输入书名：";
				cin >> strBookName;
				student.QueryBook(strBookName);
				break;
			case 2:
				//选择借书
				cout << "请输入图书ID：";
				cin >> nBookId;
				student.BorrowBook(nBookId);
				break;
			case 0:
				//选择退出登录
				bIsLogin = false;
				break;
			default:
				break;
			}
		}
		cout << "您已退出登录，按任意键退出..." << endl;
	}
	cin.get();
	cin.get();
	return 0;
}