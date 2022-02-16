#pragma once
#include "work.h"
#include <iostream>
using namespace std;

//经理类
class Manager :public Worker
{
public:
	Manager(int id,string name,int dId);
	//获取个人信息
	void showInfo();
	//获取岗位名称
	string getDeptName();
};
