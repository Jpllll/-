#pragma once
using namespace std;
#include<iostream>
#include"work.h"

class Employee :public Worker
{
public:
	Employee(int id,string name,int dId);	//构造函数

	//获取个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
