#pragma once	//防止头文件重复包含
#include<iostream>
#include"work.h"
#include"employee.h"
#include"manager.h"
#include<fstream>

using namespace std;

#define FILENAME "record.txt"

class Workmanager
{
public:
	Workmanager();	//只做声明
	void Show_menu();
	void exit_system();	//退出系统
	int m_EmpNum;	//记录职工人数
	Worker** m_EmpArray;//职工数组指针
	bool m_fileisempty;	//文件是否为空
	//添加职工
	void Add_Emp();
	//保存文件
	void Save();
	//统计文件人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//判断职工是否存在
	int is_Exist(int id);
	//删除职工
	void Del_Emp();
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();

	~Workmanager();

};