#include<iostream>
#include "workmanager.h"
//#include"work.h"
#include"employee.h"
#include"manager.h"
using namespace std;

int main()
{
	Workmanager worker;
	int choice;
	/*Worker* ww = new Employee(0001,"��ͬѧ",1);
	ww->showInfo();*/
	while (true)
	{
		worker.Show_menu();	//���ó�Ա����
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:		//�˳�ϵͳ
			worker.exit_system();
			break;
		case 1:		//����ְ��
			worker.Add_Emp();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
		}
	}

	
	
	return 0;
}