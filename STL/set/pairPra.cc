#include<iostream>
#include<string>
using namespace std;

int main()
{
	//第一种方式，创建一个pair
	pair<int, string> mypair(10, "aaa");
	cout << mypair.first << "  " << mypair.second << endl;

	//第二种 创建pair
	pair<string, string> mypair2 = make_pair("aaa", "bbb");
	//auto mypair2 = make_pair("aaa", "bbb");
	cout << mypair2.first << "  " << mypair2.second << endl;

	//第三种
	pair<int, string> mypair3 = mypair;//拷贝构造
	cout << mypair3.first << "  " << mypair3.second << endl;

	getchar();
	return 0;
}