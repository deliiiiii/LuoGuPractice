#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int max_m = 2e5 + 10;

struct node {
	int x, y, z;
}edge[max_m];

bool cmp(node a, node b)
{
	return a.z < b.z;
}

int fa[max_m];
int n_node, m_edge;
long long sum;

int GetAndSetParent(int x)
{
	return x == fa[x] ? x : fa[x] = GetAndSetParent(fa[x]);
}

int main()
{
	cin >> n_node >> m_edge;
	for (int i = 0; i <= n_node; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m_edge; i++)
	{
		cin >> edge[i].x >> edge[i].y >> edge[i].z;
	}

	sort(edge + 1, edge + 1 + m_edge, cmp);
	for (int i = 1; i <= m_edge; i++)
	{
		int x = GetAndSetParent(edge[i].x);
		int y = GetAndSetParent(edge[i].y);
		if (x == y)
			continue;
		fa[y] = x;
		sum += edge[i].z;
	}
	int ans = 0;
	for (int i = 1; i <= n_node; i++)
	{
		if (i == fa[i])
			ans++;
	}
	if (ans > 1)
		cout << "orz";
	else
		cout << sum;
	return 0;
}



