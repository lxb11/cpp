#include "myArray.h"

int main()
{
    myArray array1(10);//调用myArray的构造函数


    //设置一个数组的所有元素
    for(int i = 0; i < array1.getLen(); ++i)
    {
        array1.setData(i, i + 10);
    }

    cout << "-----------------" << endl;

    //遍历一边数组的所有元素
    for(int i = 0; i < array1.getLen(); ++i)
    {
        cout << array1.getData(i) << endl;
    }

    cout << "下面是调用拷贝构造函数的测试" << endl;
    myArray array2 = array1;//调用了array2的拷贝构造函数
    
    for(int i = 0; i < array2.getLen(); ++i)
    {
        cout << array2.getData(i) << endl;
    }
    return 0;
}

