#include "Student.h"

Student::Student()
{
}

Student::Student(User user)
{
	SetUserID(user.GetUserID());
	SetUserName(user.GetUserName());
	SetUserPWD(user.GetUserPWD());
	SetUserRole(user.GetUserRole());
}

Student::~Student()
{
}

void Student::ShowMenu()
{
	system("cls");
	cout << "     ============================欢迎使用图书馆后台管理系统：===========================" << endl;
	cout << "                                  1.新书录入2：" << endl;
	cout << "                                  2.图书查询2：" << endl;
	cout << "                                  3.用户查询2：" << endl;
	cout << "                                  4.交易记录查询2：" << endl;
	cout << "                                  1.新书录入2：" << endl;
}
