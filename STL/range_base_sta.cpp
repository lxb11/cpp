/*************************************************************************
	> File Name: range_base_sta.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 23时13分30秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;



int main()
{

    for (int i : { 2,3,5,7,9,11 } )
    {
        std::cout << i << "  ";
    }
    cout << std::endl;

    std::vector<double> vec = { 1,2,3,4,5,6 };

    for ( auto& elem : vec )
    {
        elem *= 3;
    }

    for ( auto elem : vec )
    {
        std::cout << elem << "  ";

    }
    cout << std::endl;





}
