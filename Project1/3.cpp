#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>

#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;

const int N = 500010;
int head[N], ver[N], next[N], tot, n, st, edge[N];
long long ans, dis[N];
void add(int x, int y, int z)//建图
{
	ver[++tot] = y;
	edge[tot] = z;
	next[tot] = head[x];
	head[x] = tot;
}
void dfs(int x, int fa)
{
	for (int i = head[x]; i; i = next[i])
	{
		int y = ver[i], z = edge[i];
		if (y == fa) continue;
		dfs(y, x);//继续搜子树
		dis[x] = max(dis[x], dis[y] + z); //更新这棵子树根节点和叶子节点的最大距离
	}
	for (int i = head[x]; i; i = next[i])
	{
		int y = ver[i], z = edge[i];
		if (y == fa) continue;
		ans += dis[x] - (dis[y] + z);//累加每次调整的代价
	}
}
int main()
{
	scanf("%d%d", &n, &st);
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z); add(y, x, z);//注意双向边
	}
	dfs(st, 0);
	printf("%lld", ans);
	return 0;
}