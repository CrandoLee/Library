#include <stdlib.h>
#include <iostream>
#include "User.h"
using namespace std;
class Student:public User
{
public:
	Student();
	~Student();
	void ShowMenu();
};

