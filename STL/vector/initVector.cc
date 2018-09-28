#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//vector初始化
void test0()
{
    vector<int> v1;
    vector<int> v2(10, 5); //带参数的构造函数
    vector<int> v3(v2.begin(), v2.end());
    vector<int> v4(v3);//拷贝构造

    int arr[] = {1,2,3,4};
    vector<int> v5(arr, arr + sizeof(arr) / sizeof(int));
    for(unsigned int i = 0; i < v4.size(); ++i)
    {
        cout << v4.at(i) << " ";
    }
    cout << endl;
}


void test1()
{
    vector<int> v1, v2;
    for(unsigned int i = 0; i < 10; ++i)
    {
        v1.push_back(i + 10);
    }
    for(unsigned int i = 0; i < 10; ++i)
    {
        v2.push_back(i + 20);
    }

    printVector(v1);
    printVector(v2);

    cout << "交换后" << endl;
    swap(v1, v2);
    cout << "v1 :" << endl; 
    printVector(v1);
    cout << "v2 :" << endl; 
    printVector(v2);


    //swap小技巧
    vector<int> v3;
    v3.resize(100);
    cout << "容量 " << v3.capacity() << endl;
    cout << "大小 " << v3.size() << endl;

    v3.clear();
    cout << "容量 " << v3.capacity() << endl;
    cout << "大小 " << v3.size() << endl;

    vector<int>(v3).swap(v3);//匿名对象生存空间就是这句代码执行完毕
    cout << "swap 后 v3 :" << endl; 
    cout << "容量 " << v3.capacity() << endl;
    cout << "大小 " << v3.size() << endl;



}

//赋值操作
void test2()
{
    vector<int> v1;
    v1.assign(5, 1);
    printVector(v1);

    vector<int> v2;
    v2.assign(v1.begin(), v1.end());
    printVector(v2);

    vector<int> v3;
    v3 = v1;
    printVector(v3);

}

//插入
void test3()
{
    int arr[] = {6,7,8,9};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    v.insert(v.begin(), 100);
    printVector(v);
    v.insert(v.end(), 100);
    printVector(v);
}

int main()
{
    cout << "-----------test0---------" << endl;
    test0();
    cout << "-----------test1---------" << endl;
    test1();
    cout << "-----------test2---------" << endl;
    test2();
    cout << "-----------test3---------" << endl;
    test3();
    return 0;
}

