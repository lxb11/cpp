#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

#define SALE_DEPARTMENT 1 //销售部门
#define DEV_DEPARTMENT 2 //开发部
#define FINACIAL_DEPARTMENT 3 //财务部

//multimap 案列
//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在哪个部门工作
//人员信息由：姓名 年龄 电话 工资等组成
//通过multimap进行信息的 插入 保存 显示
//分部门显示员工信息，显示全部员工信息


class Yuangong
{
public:
	string name;
	int age;
	double salary;
	string tele;
};

//创建员工 5名
void CreateYuangong(vector<Yuangong>& v)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		Yuangong yg;
		yg.name = "员工";
		yg.name += nameseed[i];

		yg.age = rand() % 30;
		yg.salary = rand() % 10000 + 10000;
		yg.tele = "+86-88888888";

		v.push_back(yg);
	}
}

//对员工指派部门
void  SetYGgroup(vector<Yuangong>& v, multimap<int, Yuangong>& group)
{
	for (vector<Yuangong>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "当前员工信息：" << endl;
		cout << "名字：" << it->name << endl;
		cout << "年龄： " << it->age << endl;
		cout << "工资:" << it->salary << endl;
		cout << "电话：" << it->tele << endl;

		int departmentID = -1;
		while (true)
		{
			cout << "请输入部门(1.销售部 2.开发部 3.财务部)" << endl;
			cin >> departmentID;

			if (departmentID == SALE_DEPARTMENT)
			{
				group.insert(make_pair(SALE_DEPARTMENT, *it));
				break;
			}
			else if (departmentID == DEV_DEPARTMENT)
			{
				group.insert(make_pair(DEV_DEPARTMENT, *it));
				break;
			}
			else if (departmentID == FINACIAL_DEPARTMENT)
			{
				group.insert(make_pair(FINACIAL_DEPARTMENT, *it));
				break;
			}
			else
			{
				cout << "输入错误， 请重新输入：" << endl;
			}
		}
	}
}

//打印员工信息
void ShowYGInfo(multimap<int, Yuangong>& group)
{
	cout << "----------------showYGInfo()----------" << endl;
	int depaertmentID = -1;
	while (true)
	{
		cout << "请输入部门(1.销售部 2.开发部 3.财务部)： 0.结束" << endl;
		cin >> depaertmentID;

		if (depaertmentID < 1 || depaertmentID > 3)
		{
			continue;
		}
		if (!depaertmentID)
		{
			break;
		}
		multimap<int, Yuangong>::iterator pos = group.find(depaertmentID);
		int num = group.count(depaertmentID);
		while (pos != group.end() && num)
		{
			cout << "当前员工信息：" << endl;
			cout << "名字：" << pos->second.name << endl;
			cout << "年龄： " << pos->second.age << endl;
			cout << "工资:" << pos->second.salary << endl;
			cout << "电话：" << pos->second.tele << endl;
			++pos;
			--num;
		}
	}
}

int main()
{
	vector<Yuangong> v;//放员工信息，未分组之前
	multimap<int, Yuangong> Ygroup;//存放分组后的员工信息
	CreateYuangong(v);//创建员工 5名
	SetYGgroup(v, Ygroup);
	ShowYGInfo(Ygroup);

	return 0;
}