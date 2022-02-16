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
	/*Worker* ww = new Employee(0001,"江同学",1);
	ww->showInfo();*/
	while (true)
	{
		worker.Show_menu();	//调用成员函数
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:		//退出系统
			worker.exit_system();
			break;
		case 1:		//增加职工
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