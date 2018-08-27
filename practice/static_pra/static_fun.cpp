#include <iostream>
using namespace std;


class Student
{
public:
    Student(int num, double score)
    {
        m_num = num;
        m_score = score;

        ++count;
        sum_socre += score;
    }

    static double getAvg()
    {
        return sum_socre / count;
    }
    
private:
    int m_num;
    double m_score;

    //定义一个记录学生的个数的静态变量
    static int count;
    static double sum_socre;//所有已经定义学生对象的总socre和
};

//初始化静态成员变量
int Student::count = 0;
double Student::sum_socre = 0;


int main()
{
    Student s1(1, 100);
    Student s2(2, 70);
    Student s3(3, 80);

    double avg = Student::getAvg();

    cout << "目前学生的平均分数是 = " << avg << endl;

    return 0;
}

