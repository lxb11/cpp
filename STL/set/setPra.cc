#include<iostream>
#include<set>
#include<functional>
using namespace std;

void printSet(set<int>& myset)
{
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//初始化
void test0()
{
	set<int> myset1;//默认构造
	set<int> myset2; //拷贝构造
}

//set容器插入和删除
void test1()
{
	set<int> myset1;
	myset1.insert(4);
	myset1.insert(5);
	myset1.insert(3);
	myset1.insert(2);
	myset1.insert(1);
	::printSet(myset1);

	//删除
	myset1.erase(myset1.begin());//删除第一个元素
	::printSet(myset1);
	myset1.erase(2);//根据元素值删除
	::printSet(myset1);
	myset1.erase(myset1.begin(), myset1.end());//myset1.clear();
	::printSet(myset1);
}

//查找
class mycompaer2 
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test2()
{
	//函数对象，也叫仿函数
	mycompaer2 mycom;
	cout << mycom(10, 20) << endl;

	//set<int> myset;//默认从小到大排序
	set<int, greater<int>> myset;
	myset.insert(4);
	myset.insert(2);
	myset.insert(1);
	myset.insert(5);
	for (set<int, greater<int>>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
	set<int>::iterator pos = myset.find(20);//返回值为2的元素所在的位置
	if (pos == myset.end())
	{
		cout << "没有查找到! " << endl;
	}
	else
	{
		cout << "查找到 ：" << *pos << endl;
	}
}

class Teacher 
{
public:
	int _id;
	int _age;
	Teacher(int id, int age): _id(id), _age(age){}
};

class mycompare3
{
public:
	bool operator()(Teacher t1, Teacher t2)
	{
		return t1._id > t2._id;
	}
};
void test3()
{
	set<Teacher,mycompare3> myset;
	Teacher t1(1, 2), t2(3, 4), t3(5, 6);
	myset.insert(t1);
	myset.insert(t2);
	myset.insert(t3);
	for (set<Teacher>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		cout << it->_id << "  " << it->_age << endl;
	}

	//set<Teacher>::iterator pos = myset.find(t2);
	//if (pos == myset.end())
	//{
	//	cout << "没有查找到! " << endl;
	//}
	//else
	//{
	//	cout << "查找到 ：" << pos->_id << "  " << pos->_age << endl;
	//}

	set<Teacher>::iterator pos = myset.find(Teacher(3, 10));//根据 _id查找
	if (pos == myset.end())
	{
		cout << "没有查找到! " << endl;
	}
	else
	{
		cout << "查找到 ：" << pos->_id << "  " << pos->_age << endl;
	}
}

void test4()
{
	set<int> myset;
	myset.insert(10);
	myset.insert(5);
	myset.insert(1);
	myset.insert(8);
	myset.insert(9);

	set<int>::iterator pos = myset.lower_bound(5); //返回大于等于5 迭代器
	if (pos == myset.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "查找到 ：" << *pos << endl;
	}

	pair<set<int>::iterator, set<int>::iterator> pos2 = myset.equal_range(5);
	if (pos2.first == myset.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "找到：" << *(pos2.first) << endl;
	}

	if (pos2.second == myset.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "找到：" << *(pos2.second) << endl;
	}
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}