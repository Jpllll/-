#include"workmanager.h"

//ͷ�ļ���д������Դ�ļ���дʵ��
Workmanager::Workmanager()
{
	m_EmpNum = 0;
	m_EmpNum = NULL;

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
	cout << "-------2.ɾ��ְ����Ϣ-------" << endl;
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
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << Add_num << "����ְ��" << endl;
	}
	else
	{
		cout << "�������������" << endl;
	}
}