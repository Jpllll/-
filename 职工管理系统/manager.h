#pragma once
#include "work.h"
#include <iostream>
using namespace std;

//������
class Manager :public Worker
{
public:
	Manager(int id,string name,int dId);
	//��ȡ������Ϣ
	void showInfo();
	//��ȡ��λ����
	string getDeptName();
};
