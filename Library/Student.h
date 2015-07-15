#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
#include <time.h>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
#include "DBUtil.h"
#include "User.h"
#include "BorrowRecord.h"
using namespace std;
class Student:public User
{
public:
	Student();
	~Student();
	void ShowMenu();
	bool QueryBook(string strBookName);
	bool BorrowBook(int nBookId);
	bool ReturnBook();
	bool ShowMyBorrowRecord();
public:
	TimeUtil m_timeUtil;
	DBUtil m_dbUtil;
};

