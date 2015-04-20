#include "FileUtil.h"


FileUtil::FileUtil()
{
}

FileUtil::~FileUtil()
{
}

User FileUtil::ReadUser(string _strUserName, string _strUserPWD)
{
	User user;
	int nUserID = 0;
	string strUserName = "";
	string strUserPWD = "";
	int nRole;
	ifstream infile("user.txt");
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			infile >> nUserID;
			infile >> strUserName;
			infile >> strUserPWD;
			infile >> nRole;
			if (strUserName == _strUserName && strUserPWD == _strUserPWD)
			{
				user.SetUserID(nUserID);
				user.SetUserName(strUserName);
				user.SetUserPWD(strUserPWD);
				user.SetUserRole(nRole);
				return user;
			}
		}
	}
	else
	{
		cout << "can not open file user.txt...";
	}

	return user;
}
