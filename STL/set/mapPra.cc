#include<iostream>
#include<map>
#include<string>
using namespace std;

//map容器初始化
void test0()
{
	//map容器的模板参数 ，需要指定key类型，value的类型
	map<int, string> mymap1;//默认构造
	map<int, string> mymap2(mymap1); //拷贝构造
}

//map插入操作
void test1()
{
	map<int, int> mymap0;

	//第一种插入方式
	mymap0.insert(pair<int, int>(1, 5));
	//第二种插入方式
	mymap0.insert(make_pair(2, 10));
	//第三种插入方式
	mymap0.insert(map<int, int>::value_type(3, 15));
	//第四种插入方式
	mymap0[4] = 20;//如果key存在，会修改容器指定key元素的值

	//四中插入方式的区别
	mymap0[2] = 100;//这种方式可以修改

	//如果你访问的key不存在，他会帮你把这个数据插入进去
	cout << " key :" << mymap0[20] << endl;

	pair<map<int, int>::iterator, bool> ret = mymap0.insert(map<int, int>::value_type(3, 15));
	if (ret.second)
	{
		cout << "插入成功！" << endl;
	}
	else
	{
		cout << "插入失败！" << endl;
	}

	pair<map<int, int>::iterator, bool> ret1 = mymap0.insert(map<int, int>::value_type(5, 15));
	if (ret1.second)
	{
		cout << "插入成功！" << endl;
	}
	else
	{
		cout << "插入失败！" << endl;
	}

	for (map<int, int>::iterator it = mymap0.begin(); it != mymap0.end(); ++it)
	{
		cout << "key = " << it->first << "  " << "value = " << it->second << endl;
	}


}

int main()
{
	cout << "-----------test1-----------" << endl;
	test1();
	return 0;
}