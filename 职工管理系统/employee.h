#pragma once
using namespace std;
#include<iostream>
#include"work.h"

class Employee :public Worker
{
public:
	Employee(int id,string name,int dId);	//���캯��

	//��ȡ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
