#include "goods.h"

int main()
{
    int choice = 0;

    Goods* head = NULL;//所有货物的表头

    do
    {
        cout << "1 进货" << endl;
        cout << "2 出货" << endl;
        cout << "3 退出" << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            //进货
            cout << "请输入要创建货物的重量" << endl;
            int w;
            cin >> w;
            buy(head, w);
            break;
        case 2:
            //出货
            sale(head);

            break;
        case 3:
            //退出
            return 0;
            break;
        default:
            break;
        }

        cout << "此时仓库中有" << Goods::getTotal() << "重量的货物" << endl;
    }while(1);



    return 0;
}

