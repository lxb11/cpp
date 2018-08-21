## 变量实用增强
```
//gcc编译不报错，g++编译报错
#include<iostreaam>

int g_var;
int g_var = 1;

int main()
{
    
}
```

## struct
```
struct student{
    int id;
    char name[32];
}

//
struct student stu1;

//cpp

student stu1;

```

## 函数检测,C++编译器对函数形参传递，函数返回值作了严格的检查

```
//c,编译通过,cpp编译报错
int f(int i){
    printf("%d\n", i);
}

int test()
{
    f(1, 2, 3);
}

//c可以编译通过，cpp编译出错
fun(){

    return 3;
}


```
## 三目运算符的增强

```
//c,编译不通过，提示：
void test()
{
    int a = 10;
    int b = 20;

    (a < b ? a : b) = 30;//返回的是一个数值， 10 = 30
    *(a < b ? &a : &b) = 30;//返回地址，给地址赋值
}

//cpp,编译通过
void test_cpp()
{
    int a = 10;
    int b = 20;
    
    (a < b ? a : b) = 30;//返回的是a变量的别名，返回引用

    (a < b ? 10 : b) = 30;//三目运算符，如果作为左值， 那么返回结果不能有常量
}

```
## const增强
```
//c语言中的const
void test1()
{
    const int a = 10;
    int const b = 20;//const int ,int const 是等价的

    int *p = (int*)&a;
    *p = 20;//c语言中可以通过间接指针赋值改变const变量
    printf("%d\n", a);//20
}

void test2()//cpp编译通过，c语言编译不通过
{
    const int a = 2;
    const int b = 4;//说明c语言中的const并不会是一个常量，
    //是一个变量，只是加了只读属性;cpp中对const的增强，变成了真正的常量

    int array[a + b] = 0;//数组里类型大小是固定，
    //将两个变量做长度，编译器无法确定长度
}

//cpp对const的加强
void test_cpp1()
{
    const int a = 10;//必须初始化，const修饰的常量必须初始化，
    //此时a就是一个符号，存放在符号表里

    int *p = (int *)&a;//当C++编译器为了兼容c语言，会临时在栈上开辟一个临时的空间，
    //这个变量是匿名的，
    *p = 20;//*p改变的是临时的变量，而不是常量的a符号
    cout << a; //10
}
```
## const和define区别
1. define和const变量在编译的阶段不一样，define是预处理，const是编译器
2. const是编译器处理，完全符合编译器的逻辑判断和词法分析，define没有区域划分
3. 预处理：简单的代码展开；编译器：语法校验，词法分析校验
```
void test2()
{
    const int tt;
#defien ff 22
}

void test3()
{
    cout << tt << endl;//编译报错
    cout << ff << endl;
}
```

## 枚举增强
```
//c

enum season{
    SPR = 0,
    SUM,
    AUT,
    WIN
}

void test4()
{
    enum season s = SPR;

    s = 0;
    s = 1;
    s = 2;
    s = 3;//c语言对枚举类型的赋值，是可以通过枚举的值，直接赋值的
}

//cpp
void test_cpp4()
{
    enum season s = SPR;

    s = SUM;//，只能通过枚举变量赋值，为了增加枚举的可读性
    s = 2;//编译出错

}
```
## cpp可以有默认参数
```
int func1(int x = 100)
{
    cout << "func: x = " << x << endl;
    return 0;
}

//默认参数，必须是从右向左设置，只有一个默认参数时，必须放到最右边
int volume(int width, int len = 40, int hight = 10)
{
    return width * len * hight;
}

//占位符
int func1(int a, int)
{
    return a;
}

int mian(void)
{
    int x = 10;

    func();
    func(x);
}

```


