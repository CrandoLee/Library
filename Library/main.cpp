#include <iostream>
#include "User.h"
#include "FileUtil.h"
#include "Manager.h"
#include "DBUtil.h"
#include "Student.h"
#include "Book.h"
using namespace std;

int main()
{
	string strUserName = "";
	string strUserPWD = "";
	User user;
	cout << "             请输入用户名：";
	cin >> strUserName;
	cout << endl;
	cout << "             请输入密码：";
	cin >> strUserPWD;
	cout << endl;
	DBUtil dbUtil;
	user = dbUtil.ReadUser(strUserName, strUserPWD);
	if (user.GetUserID() == 0)
	{
		Manager manager(user);
		manager.ShowMenu();
		int command = -1;		//选择命令
		while (1)
		{
			cout << "请选择命令：";
			cin >> command;
			switch (command)
			{
			case 1:
				Book book;
				cout << "您选择的是新增图书功能：";
				cout << "请输入图书名称：";
			default:
				break;
			}
		}
	}
	else
	{
		Student student;
		student.ShowMenu();
	}
	cin.get();
	cin.get();
	return 0;
}