#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>

#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int max_n = 1 * 1e2 + 10;
struct Edge
{
	int target;
	int value;
	int next;
} edge[max_n * max_n];
struct Answer
{
	int index;
} ans[max_n];
int m, n;
int temp_this, temp_target, Upmost,count_edge = 0;
int cum[max_n], linearForwardStar[max_n], visited[max_n];
queue <int> que;
bool didPrint = 0 , isOutDot[max_n];
bool cmp(Answer x, Answer y)
{
	return x.index < y.index;
}
void SetEdge(int u, int v, int w)
{
	
	count_edge++;
	edge[count_edge].target = v;
	edge[count_edge].value = w;
	edge[count_edge].next = linearForwardStar[u];
	linearForwardStar[u] = count_edge;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		visited[i] = isOutDot[i] = 0;
		scanf("%d%d", &cum[i], &Upmost);
		if (cum[i] > 0)
		{
			que.push(i); 
			visited[i] = 1;
		}
		else cum[i] -= Upmost;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		SetEdge(u, v, w);
		isOutDot[u] = 1;
	}
	while (!que.empty())
	{
		temp_this = que.front();
		que.pop();
		if (cum[temp_this] <= 0) 
			continue;
		for (int i = linearForwardStar[temp_this]; i; i = edge[i].next)
		{
			temp_target = edge[i].target;
			cum[temp_target] += edge[i].value * cum[temp_this];
			if (!visited[temp_target])
			{
				que.push(temp_target);
				visited[temp_target] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!isOutDot[i] && cum[i] > 0)
		{
			printf("%d %d\n", i, cum[i]);
			didPrint = 1;
		}
	}

	if (!didPrint)
	{
		cout << "NULL";
	}
	return 0;
}

