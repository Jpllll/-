#pragma once	//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"work.h"
#include"employee.h"
#include"manager.h"

using namespace std;

class Workmanager
{
public:
	Workmanager();	//ֻ������
	void Show_menu();
	void exit_system();	//�˳�ϵͳ
	int m_EmpNum;	//��¼ְ������
	Worker** m_EmpArray;//ְ������ָ��
	//���ְ��
	void Add_Emp();

	~Workmanager();

};