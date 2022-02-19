#include"workmanager.h"

//ͷ�ļ���д������Դ�ļ���дʵ��
Workmanager::Workmanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//1���ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	
	//2���ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}

	//3���ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	cout << "ְ������Ϊ��" << num << endl;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

}

Workmanager::~Workmanager()
{
	cout << "������������" << endl;
}

void Workmanager::Show_menu()
{
	cout << "------------------------------" << endl;
	cout << "-----��ӭʹ��ְ������ϵͳ-----" << endl;
	cout << "-------0.�˳��������-------" << endl;
	cout << "-------1.����ְ����Ϣ-------" << endl;
	cout << "-------2.��ʾְ����Ϣ-------" << endl;
	cout << "-------3.ɾ����ְԱ��-------" << endl;
	cout << "-------4.�޸�ְ����Ϣ-------" << endl;
	cout << "-------5.����ְ����Ϣ-------" << endl;
	cout << "-------6.���ձ������-------" << endl;
	cout << "-------7.��������ĵ�-------" << endl;
	cout << "------------------------------" << endl;
	cout << endl;
}

void Workmanager::exit_system()
{
	system("pause");
	exit(0);
}

//���ְ��
void Workmanager::Add_Emp()
{
	cout << "������Ҫ��ӵ�������" << endl;
	int Add_num = 0;
	cin >> Add_num;
	if (Add_num > 0)
	{
		//���
		int new_size = Add_num + this->m_EmpNum;
		//�����¿ռ�
		Worker** newSpace = new Worker* [new_size];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < Add_num; i++)
		{
			int id;	//ְ�����
			string name;	//ְ������
			int dSelect;	//����ѡ��

			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
			cin >> id;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Id == id)
				{
					cout << "�ñ���Ѵ��ڣ������������ţ�" << endl;
					return;
				}
			}
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ���Ĳ���" << endl;
			cout << "1������ͨԱ��" << endl;
			cout << "2������" << endl;
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
			//��������ְ�����浽������ȥ
			newSpace[this->m_EmpNum+i] = new_emp;
		}
		//�����¿ռ��ָ��
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = new_size;

		this->m_fileisempty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << Add_num << "����ְ��" << endl;

		this->Save();
		
	}
	else
	{
		cout << "�������������" << endl;
	}
}

//�������ļ�
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

//ͳ���ļ�����
int Workmanager::get_EmpNum()
{
	int id;	//ְ�����
	string name;	//ְ������
	int dSelect;	//����ѡ��

	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//���ļ�
	int num = 0;

	while(ifs >> id && ifs >> name && ifs >> dSelect)
	{
		num++;
	}
	return num;
}

//��ʼ��Ա��
void Workmanager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;	//ְ�����
	string name;	//ְ������
	int dSelect;	//����ѡ��
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

	//�ر��ļ�
	ifs.close();
}

//��ʾְ��
void Workmanager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_fileisempty == true)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����,��������
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
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		int Del_Id;
		cout << "��������Ҫɾ��ְ���ı�ţ�" << endl;
		cin >> Del_Id;

		int ret = this->is_Exist(Del_Id);
		if (ret == -1)
		{
			cout << "�����ڸ�ְ����" << endl;
			return;
		}
		for (int i = ret; i < this->m_EmpNum - 1; i++)
		{
			//����ǰ��
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;	//���������м�¼����Ա����
		this->Save();
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void Workmanager::Mod_Emp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << endl;
		return;
	}
	cout << "������Ҫ�޸ĵ�ְ���ı�ţ�" << endl;
	int id;
	cin >> id;
	int ret = this->is_Exist(id);
	if (ret != -1)
	{
		delete this->m_EmpArray[ret];
		cout << "��ѯ����ţ�" << id << "��ְ������������ְ���ţ�" << endl;
		int new_id;
		cin >> new_id;
		cout << "������ְ������������" << endl;
		string new_name;
		cin >> new_name;
		cout << "������ְ���ĸ�λ��" << endl;
		cout << "1������ְͨ��" << endl;
		cout << "2������" << endl;
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
		//�������ݵ�������
		this->m_EmpArray[ret] = new_worker;
		//���浽�ļ���
		this->Save();
		cout << "�޸�ְ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ��޸�ʧ�ܣ�" << endl;
	}
}

//����ְ��
void Workmanager::Find_Emp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ�Ϊ�գ�����ʧ��" << endl;
		return;
	}

	cout << "��������ҷ�ʽ��" << endl;
	cout << "1������Ų���" << endl;
	cout << "2������������" << endl;
	int Find_way;
	cin >> Find_way;

	if (Find_way == 1)
	{
		cout << "������Ҫ���ҵı�ţ�" << endl;
		int Find_id = 0;
		cin >> Find_id;
		if (this->is_Exist(Find_id) != -1)
		{
			this->m_EmpArray[this->is_Exist(Find_id)]->showInfo();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	else if (Find_way == 2)
	{
		cout << "������Ҫ���ҵ�������" << endl;
		string Find_name;
		cin >> Find_name;

		bool Flag = false;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Name == Find_name)
			{
				cout << "���ҳɹ���" << endl;
				this->m_EmpArray[i]->showInfo();
				Flag = true;
			}
		}
	if(Flag==false)
	{
		cout << "����ʧ�ܣ����޴��ˣ�" << endl;
	}
		
	}
	//�����������
	system("pause");
	system("cls");
}