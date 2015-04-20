#include <iostream>
#include <string>
#include <fstream> 
#include "User.h"
using namespace std;
class FileUtil
{
public:
	FileUtil();
	~FileUtil();
	static User ReadUser(string strUserName, string strUserPWD);
};

