#include <iostream>
#include <cstring>
using namespace std;


class AdvHero
{
public:
    int sex;
    char name[64];//成员变量
    
    //成员函数
    void printInfo()
    {
        cout << "sex = " << sex << endl;
        cout << "name = " << name << endl;
    }
};


class Mydata
{
public:
    int year;
    int month;
    int day;

    void inti()
    {
        cout << "year,month,yaer" << endl;
        cin >> year;
        cin >> month;
        cin >> day;
    }
    void printData()
    {
        cout << "Data is" << year << month << day << endl;
    }
};

class Cricle
{
private:
    double m_r;//半径
public:
    //一般修改一个私有成员的方法叫get set:
    void setR(double r)
    {
        m_r = r;
    }
    double getCirth()
    {
        return m_r * 3.14 * 2;
    }
    double getR()
    {
        return m_r;
    }


};


int main()
{


    AdvHero chunBox;

    chunBox.sex = 1;
    strcpy(chunBox.name, "chunBox");
    chunBox.printInfo();


    Cricle c1;
    c1.setR(10.0);
    cout << "c1的半径" << c1.getR();








    return 0;
}

