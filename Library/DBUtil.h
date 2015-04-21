#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "EndOfFile") 
#include <iostream>
#include <iomanip> 
#include "User.h"

class DBUtil
{
public:
	DBUtil();
	~DBUtil();
	User ReadUser(string strUserName, string strUserPWD);
	
};

