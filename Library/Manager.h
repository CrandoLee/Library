#include <stdlib.h>
#include <iostream>
#include "User.h"
using namespace std;
#pragma once
class Manager:public User
{
public:
	Manager();
	~Manager();
	void ShowMenu();
};

