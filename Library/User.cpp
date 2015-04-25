#include <iostream>
#include "User.h"
using std::cout;
User::User()
{
}


User::~User()
{
}

void User::SetUserID(int nID)
{
	m_nID = nID;
}

int User::GetUserID(){
	return m_nID;
}

void User::SetUserName(string sName)
{
	m_strName = sName;
}

string User::GetUserName()
{
	return m_strName;
}

void User::SetUserPWD(string sPassword)
{
	m_strPassword = sPassword;
}

string User::GetUserPWD()
{
	return m_strPassword;
}

void User::SetUserRole(int nRole)
{
	m_nRole = nRole;
}

int User::GetUserRole()
{
	return m_nRole;
}

