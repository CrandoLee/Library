#include "Manager.h"

Manager::Manager()
{
}

Manager::Manager(User user)
{
	SetUserID(user.GetUserID());
	SetUserName(user.GetUserName());
	SetUserPWD(user.GetUserPWD());
	SetUserRole(user.GetUserRole());
}

Manager::~Manager()
{
}


void Manager::ShowMenu()
{
	system("cls");
	cout << "     ============================欢迎使用图书馆后台管理系统：===========================" << endl;
	cout << "                                  1.新书录入：" << endl;
	cout << "                                  2.图书查询：" << endl;
	cout << "                                  3.用户查询：" << endl;
	cout << "                                  4.交易记录查询：" << endl;
	cout << "                                  1.新书录入：" << endl;
}