#include<iostream>
using namespace std;

#define n 8
char a[200][201];
int open[2000], openlen = 2000;
int head, tail;
int endrow, endcol;//终点横,纵坐标
				   //判断队列是否为空
int emptyopen()
{
	if (head == tail)
		return 1;
	return 0;
}
//取结点
int takeoutopen()
{
	int u;
	u = open[head++];
	head = head % openlen;
	return u;
}
int canmoveto(int row, int col, int *p, int *q, int i)
{
	int r = row, c = col;
	switch (i)
	{
	case 0: c -= 2; r--; break;
	case 1: r++, c -= 2; break;
	case 2: c += 2; r--; break;
	case 3: r++; c += 2; break;
	case 4:c--; r -= 2; break;
	case 5:r += 2; c--; break;
	case 6:r -= 2; c++; break;
	case 7:r += 2; c++; break;
	}
	*p = r;
	*q = c;
	if (r >= 0 && c >= 0 && r<n && c<n && a[r][c] == 0)
		return 1;
	return 0;
}
//判断是否到达终点
int isaim(int row, int col)
{
	if (row == endrow - 1 && col == endcol - 1)
		return 1;
	return 0;
}

int used(int row, int col)
{
	if (a[row][col] == 0)
		return 0;
	return 1;
}
//加入新结点
void addtoopen(int row, int col)
{
	int u;
	u = row * n + col;
	open[tail++] = u;
	tail = tail % openlen;
}
//寻找最短步长
int search(int row, int col)
{
	int u, r, c, num = 0, i = 0;
	while (!emptyopen())
	{
		u = takeoutopen();
		row = u / n;
		col = u % n;
		num = a[row][col];
		for (i = 0; i<8; i++)
		{
			if (canmoveto(row, col, &r, &c, i))
			{
				if (isaim(r, c)) {
					return(num + 1);//返回最短步长
				}
				if (!used(r, c))//没到达终点
				{
					a[r][c] = num + 1;
					addtoopen(r, c);
				}
			}
		}
	}
	return 0;
}
//主函数
int main()
{
	int i, row, col, j;
	int b[100], t = 0;
	cin >> row >> col >> endrow >> endcol;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			a[i][j] = 0;

	head = 0;
	tail = 1;
	open[0] = (row - 1) * n + col - 1;
	b[t++] = search(row - 1, col - 1);
	for (i = 0; i < t; i++)
		cout << b[i];
	return 0;
}
