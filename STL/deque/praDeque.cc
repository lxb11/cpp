#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <numeric>
using namespace std;




//选手类
class Player
{
public:
    Player(string name, int score):_name(name), _score(score){}
    string _name;
    int _score;
};

//创建选手
void CreatePlayer(vector<Player>& v)
{
    string nameseed = "ABCDEF";
    for(int i = 0; i < 5; ++i)
    {
        string name = "选手";
        name += nameseed[i];

        Player p(name, 0); //创建选手
        v.push_back(p);
    }
}


bool mycompare(int v1, int v2)
{
    return v1 > v2;//从大到小
}

//打分
void SetPlayerScore(vector<Player>& plist)
{
    deque<int> dscore;
    for(vector<Player>::iterator it = plist.begin(); it != plist.end(); ++it)
    {
        for(int i = 0; i < 10; ++i)
        {
            int score = 50 + rand() % 50;//打分
            dscore.push_back(score);
        }

        //排序
        sort(dscore.begin(), dscore.end(), mycompare);
        dscore.pop_back();//去除最低分
        dscore.pop_front();//去除最高分

        //分数总结
        it->_score = accumulate(dscore.begin(), dscore.end(), 0) / dscore.size();
    }

}

//显示5名选手得分
void ShowPlayScore(vector<Player>& plist)
{
    for(vector<Player>::iterator it = plist.begin(); it != plist.end(); ++it)
    {
        cout << "姓名：" << it->_name << "   分数：" << it->_score << endl;
    }

}

int main()
{
    //评委打分案例
    //创建5个选手(姓名， 得分)，10个评委对5各选手打分
    //得分规则，去除最低分，最高分，去除平均分
    //按得分对5名选手进行排名
    

    vector<Player> vPlayer;//存放我们选手的信息
    CreatePlayer(vPlayer);//创建选手
    SetPlayerScore(vPlayer);
    ShowPlayScore(vPlayer);//显示5名选手得分


    return 0;
}

