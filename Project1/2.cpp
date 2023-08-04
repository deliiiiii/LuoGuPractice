#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;

const int max_n = 1 * 1e1 + 10;
const int max_m = 1 * 1e1 + 10;
int n, m,index_root;
int count_slash[max_n] = { 0,1,2,5,11,23,47,95,191,383,767 };
int deep[max_n] = { 0,1,3,8,19,42,89,184,375,758,1525 };
char picture[2001][2001];
bool isDeleted[40000001];
void SetPicture(int k, int depth, int x, int y)
{
	if (isDeleted[k] == 1) return;
	if (depth > n) return;
	picture[x][y] = 'o';
	if (!isDeleted[k * 2] && !(depth >= n))
	{
		int x1 = x, y1 = y;
		for (int i = 1; i <= count_slash[n - depth]; i++)
		{
			x1--;
			y1++;
			picture[x1][y1] = '/';
		}
		SetPicture(k * 2, depth + 1, x1 - 1, y1 + 1);
	}
	if (!isDeleted[k << 1 | 1] && !(depth >= n))
	{
		int x2 = x, y2 = y;
		for (int i = 1; i <= count_slash[n - depth]; i++)
		{
			x2++;
			y2++;
			picture[x2][y2] = '\\';
		}
		SetPicture(k * 2 + 1, depth + 1, x2 + 1, y2 + 1);
	}
}
void Init()
{
	for (int i = 1; i <= 2000; i++)
	{
		for (int j = 1; j <= 2000; j++)
		{
			picture[i][j] = ' ';
		}
	}
}
void Print()
{
	for (int i = 1; i <= deep[n]; i++)
	{
		for (int j = 1; j <= index_root * 2; j++)
		{
			cout << picture[j][i];
		}
		cout << endl;
	}
}
int main()
{
	Init();
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		isDeleted[int(pow(2, a - 1) - 1 + b)] = 1;
	}
	index_root = pow(2, n - 1) * 6 / 4;
	SetPicture(1, 1, index_root, 1);
	Print();
}