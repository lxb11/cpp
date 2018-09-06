#include "myArray.h"

int main()
{
    myArray array1(10);//调用myArray的构造函数


    //设置一个数组的所有元素
    for(int i = 0; i < array1.getLen(); ++i)
    {
        array1[i] = i + 10;
    }

    cout << "----操作符重载测试----" << endl;

    //遍历一边数组的所有元素
    /*for(int i = 0; i < array1.getLen(); ++i)
    {
        cout << array1[i] << endl;
    }*/

    cout << array1 << endl;

    
    myArray array3(5);
    cin >> array3;

    cout << "下面是调用拷贝构造函数的测试" << endl;
    myArray array2 = array1;//调用了array2的拷贝构造函数
    
    for(int i = 0; i < array2.getLen(); ++i)
    {
        cout << array2.getData(i) << endl;
    }

    cout << "------array3 = array2---------" << endl;

    array2 = array3;
    cout << array3 << endl;

    cout << "==操作符的重载测试" << endl;
    if(array3 == array2)
    {
        cout << "array3 , array2相等" << endl;
    }
    
    cout << "!=操作符的重载测试" << endl;
    if(array2 != array1)
    {
        cout << "array2 ,array1不相等" << endl;
    }

    return 0;
}

