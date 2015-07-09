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
	cout << "             ÇëÊäÈëÓÃ»§Ãû£º";
	cin >> strUserName;
	cout << endl;
	cout << "             ÇëÊäÈëÃÜÂë£º";
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
		manager.ShowMenu();
		int command = -1;		//Ñ¡ÔñÃüÁî
		while (1)
		{
			cout << "ÇëÑ¡ÔñÃüÁî£º";
			cin >> command;
			switch (command)
			{
			case 1:
				manager.AddBook();
				break;
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