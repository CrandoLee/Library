#include "Student.h"

Student::Student()
{
}


Student::~Student()
{
}

void Student::ShowMenu()
{
	system("cls");
	cout << "==========================欢迎使用图书馆后台管理系统：==========================" << endl;
	cout << "                              1.查询图书" << endl;
	cout << "                              2.借阅图书" << endl;
	cout << "                              3.归还图书" << endl;
	cout << "                              4.查看借阅" << endl;
	cout << "                              0.退出登录" << endl;
}
