#pragma once	//��ֹͷ�ļ��ظ�����
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
	Workmanager();	//ֻ������
	void Show_menu();
	void exit_system();	//�˳�ϵͳ
	int m_EmpNum;	//��¼ְ������
	Worker** m_EmpArray;//ְ������ָ��
	bool m_fileisempty;	//�ļ��Ƿ�Ϊ��
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void Save();
	//ͳ���ļ�����
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//�ж�ְ���Ƿ����
	int is_Exist(int id);
	//ɾ��ְ��
	void Del_Emp();
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();

	~Workmanager();

};