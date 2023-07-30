#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
int f[10005];

int SetParent(int cur, int parent)
{
	if (f[cur] != cur)
	{
		f[cur] = SetParent(f[cur], parent);
	}
	else
	{
		return f[cur] = parent;
	}
}
int FindParent(int cur)
{
	if (f[cur] != cur)return FindParent(f[cur]);
	return cur;
}
bool Check(int e1, int e2)
{
	return FindParent(e1) == FindParent(e2);
}
int main() 
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int cata, elem_1, elem_2;
		cin >> cata >> elem_1 >> elem_2;
		if (cata == 1)
		{
			if (!Check(elem_1, elem_2))
			{
				SetParent(elem_1, elem_2);
			}
		}
		else if (cata == 2)
		{
			if (Check(elem_1, elem_2))cout << "Y" << endl;
			else cout << "N" << endl;
		}
	}
	return 0;
}








