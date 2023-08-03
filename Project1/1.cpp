#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <queue>
#include<algorithm>
#include<cstring>
using namespace std; 

const int max_n = 1 * 1e2 + 10;
const int max_m = 1 * 1e4 + 10;
int n, m, ans = 0;
int dis[101][101], a[10001];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &dis[i][j]);
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}
		}
	}
	for (int i = 2; i <= m; i++)
	{
		ans += dis[a[i - 1]][a[i]];
	}
	cout << ans;
	return 0;
}