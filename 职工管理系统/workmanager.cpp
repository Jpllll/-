#include"workmanager.h"

//头文件中写声明，源文件中写实现
Workmanager::Workmanager()
{
	m_EmpNum = 0;
	m_EmpNum = NULL;

}

Workmanager::~Workmanager()
{
	cout << "析构函数调用" << endl;
}

void Workmanager::Show_menu()
{
	cout << "------------------------------" << endl;
	cout << "-----欢迎使用职工管理系统-----" << endl;
	cout << "-------0.退出管理程序-------" << endl;
	cout << "-------1.增加职工信息-------" << endl;
	cout << "-------2.删除职工信息-------" << endl;
	cout << "-------3.删除离职员工-------" << endl;
	cout << "-------4.修改职工信息-------" << endl;
	cout << "-------5.查找职工信息-------" << endl;
	cout << "-------6.按照编号排序-------" << endl;
	cout << "-------7.清空所有文档-------" << endl;
	cout << "------------------------------" << endl;
	cout << endl;
}

void Workmanager::exit_system()
{
	system("pause");
	exit(0);
}

//添加职工
void Workmanager::Add_Emp()
{
	cout << "请输入要添加的人数：" << endl;
	int Add_num = 0;
	cin >> Add_num;
	if (Add_num > 0)
	{
		//添加
		int new_size = Add_num + this->m_EmpNum;
		//开辟新空间
		Worker** newSpace = new Worker* [new_size];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < Add_num; i++)
		{
			int id;	//职工编号
			string name;	//职工姓名
			int dSelect;	//部门选择

			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工的部门" << endl;
			cout << "1代表普通员工" << endl;
			cout << "2代表经理" << endl;
			cin >> dSelect;
			Worker* new_emp=NULL;
			switch (dSelect)
			{
			case 1:
				new_emp = new Employee(id, name, dSelect);
				break;
			case 2:
				new_emp = new Manager(id, name, dSelect);
				break;
			default:
				break;
			}
			//将创建的职工保存到数组中去
			newSpace[this->m_EmpNum+i] = new_emp;
		}
		//更改新空间的指向
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = new_size;
		//提示添加成功
		cout << "成功添加" << Add_num << "名新职工" << endl;
	}
	else
	{
		cout << "输入的人数错误" << endl;
	}
}