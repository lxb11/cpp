#include "MyVector.h"

int main()
{
    MyVector<int> vec1(10);
    for(int i = 0; i < 10; ++i)
    {
        vec1[i] = 10 + i;
    }
    cout << "vec1-----" << endl;
    cout << vec1 << endl;
    
    
    MyVector<int> vec2(vec1);//vec2 = vec1;拷贝构造
    cout << "vec2------" << endl;
    cout << vec2 << endl;

    MyVector<int> vec3;
    vec3 = vec2;//调用 = 号赋值
    cout << "vec3------" << endl;
    cout << vec3 << endl;


    MyVector<char> vec4(10);
    for(int i = 0; i < 10; ++i)
    {
        vec4[i] = 'a' + i;
    }
    cout << "vec4-----" << endl;
    cout << vec4 << endl;
    
    MyVector<char> vec5(vec4);//vec5 = vec6;拷贝构造
    cout << "vec5------" << endl;
    cout << vec5 << endl;

    MyVector<char> vec6;
    vec6 = vec5;//调用 = 号赋值
    cout << "vec6------" << endl;
    cout << vec6 << endl;


    return 0;
}

