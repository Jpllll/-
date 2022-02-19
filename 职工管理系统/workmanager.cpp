#include"workmanager.h"

//头文件中写声明，源文件中写实现
Workmanager::Workmanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//1、文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	
	//2、文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}

	//3、文件存在，并且记录数据
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	cout << "职工人数为：" << num << endl;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

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
	cout << "-------2.显示职工信息-------" << endl;
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
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Id == id)
				{
					cout << "该编号已存在，请重新输入编号！" << endl;
					return;
				}
			}
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

		this->m_fileisempty = false;

		//提示添加成功
		cout << "成功添加" << Add_num << "名新职工" << endl;

		this->Save();
		
	}
	else
	{
		cout << "输入的人数错误" << endl;
	}
}

//保存入文件
void Workmanager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//统计文件人数
int Workmanager::get_EmpNum()
{
	int id;	//职工编号
	string name;	//职工姓名
	int dSelect;	//部门选择

	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//读文件
	int num = 0;

	while(ifs >> id && ifs >> name && ifs >> dSelect)
	{
		num++;
	}
	return num;
}

//初始化员工
void Workmanager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;	//职工编号
	string name;	//职工姓名
	int dSelect;	//部门选择
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dSelect)
	{
		Worker* worker = NULL;
		if (dSelect == 1)
		{
			worker = new Employee(id, name, dSelect);
		}
		else if (dSelect == 2)
		{
			worker = new Manager(id, name, dSelect);
		}
		this->m_EmpArray[index++] = worker;
	}

	//关闭文件
	ifs.close();
}

//显示职工
void Workmanager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_fileisempty == true)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//判断职工是否存在,返回行数
int Workmanager::is_Exist(int id)
{
	int index;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			return index;
			break;
		}
	}
	return -1;
}

void Workmanager::Del_Emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		int Del_Id;
		cout << "请输入你要删除职工的编号：" << endl;
		cin >> Del_Id;

		int ret = this->is_Exist(Del_Id);
		if (ret == -1)
		{
			cout << "不存在该职工！" << endl;
			return;
		}
		for (int i = ret; i < this->m_EmpNum - 1; i++)
		{
			//数据前移
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;	//更新数组中记录的人员个数
		this->Save();
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

//修改职工
void Workmanager::Mod_Emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件为空或不存在！" << endl;
		return;
	}
	cout << "请输入要修改的职工的编号：" << endl;
	int id;
	cin >> id;
	int ret = this->is_Exist(id);
	if (ret != -1)
	{
		delete this->m_EmpArray[ret];
		cout << "查询到编号：" << id << "的职工，请输入新职工号：" << endl;
		int new_id;
		cin >> new_id;
		cout << "请输入职工的新姓名：" << endl;
		string new_name;
		cin >> new_name;
		cout << "请输入职工的岗位：" << endl;
		cout << "1代表普通职工" << endl;
		cout << "2代表经理" << endl;
		int new_dSelect;
		cin >> new_dSelect;
		Worker* new_worker = NULL;
		switch (new_dSelect)
		{
		case 1:
			new_worker = new Employee(new_id, new_name, new_dSelect);
			break;
		case 2:
			new_worker = new Manager(new_id, new_name, new_dSelect);
			break;
		default:
			break;
		}
		//更新数据到数组中
		this->m_EmpArray[ret] = new_worker;
		//保存到文件中
		this->Save();
		cout << "修改职工成功！" << endl;
	}
	else
	{
		cout << "查无此人，修改失败！" << endl;
	}
}

//查找职工
void Workmanager::Find_Emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或为空，查找失败" << endl;
		return;
	}

	cout << "请输入查找方式：" << endl;
	cout << "1代表按编号查找" << endl;
	cout << "2代表按姓名查找" << endl;
	int Find_way;
	cin >> Find_way;

	if (Find_way == 1)
	{
		cout << "请输入要查找的编号：" << endl;
		int Find_id = 0;
		cin >> Find_id;
		if (this->is_Exist(Find_id) != -1)
		{
			this->m_EmpArray[this->is_Exist(Find_id)]->showInfo();
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
	else if (Find_way == 2)
	{
		cout << "请输入要查找的姓名：" << endl;
		string Find_name;
		cin >> Find_name;

		bool Flag = false;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Name == Find_name)
			{
				cout << "查找成功！" << endl;
				this->m_EmpArray[i]->showInfo();
				Flag = true;
			}
		}
	if(Flag==false)
	{
		cout << "查找失败，查无此人！" << endl;
	}
		
	}
	//按任意键清屏
	system("pause");
	system("cls");
}