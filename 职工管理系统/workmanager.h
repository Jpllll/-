#pragma once	//防止头文件重复包含
#include<iostream>
#include"work.h"
#include"employee.h"
#include"manager.h"

using namespace std;

class Workmanager
{
public:
	Workmanager();	//只做声明
	void Show_menu();
	void exit_system();	//退出系统
	int m_EmpNum;	//记录职工人数
	Worker** m_EmpArray;//职工数组指针
	//添加职工
	void Add_Emp();

	~Workmanager();

};