//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//#include<math.h>
//
//#include<vector>
//#include<stack>
//#include<queue>
//using namespace std;
//const int N = 1 * 1e2 + 10;
//struct edge 
//{
//	int to;
//	int val;
//	int nxt;
//} e[N * N];
//struct answer 
//{
//	int id;
//} ans[N];
//int h, i, m, n, t, u, v, w, U, c[N], hd[N], out[N], vis[N];
//queue <int> que;
//int cnt = 0, flag = 0;
//bool cmp(answer aa, answer bb)
//{
//	return aa.id < bb.id;
//}
//void build(int u, int v, int w)
//{
//	cnt++;
//	e[cnt].to = v;
//	e[cnt].val = w;
//	e[cnt].nxt = hd[u];
//	hd[u] = cnt;
//}
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (i = 1; i <= n; i++)
//	{
//		vis[i] = out[i] = 0;
//		scanf("%d%d", &c[i], &U);
//		if (c[i] > 0)
//		{
//			que.push(i); vis[i] = 1;
//		}
//		else c[i] -= U;
//	}
//	for (i = 1; i <= m; i++)
//	{
//		scanf("%d%d%d", &u, &v, &w);
//		build(u, v, w);
//		out[u] = 1;//out表示有无出边，用于最后找输出层
//	}
//	while (!que.empty())
//	{
//		h = que.front(); que.pop();
//		if (c[h] <= 0) continue;
//		for (i = hd[h]; i; i = e[i].nxt)
//		{
//			t = e[i].to;
//			c[t] += e[i].val * c[h];
//			if (!vis[t])
//			{
//				que.push(t);
//				vis[t] = 1;
//			}
//		}
//	}
//	for (i = 1; i <= n; i++)
//	{
//		if (!out[i] && c[i] > 0)
//		{
//			printf("%d %d\n", i, c[i]);
//			flag = 1;
//		}
//	}
//		
//	if (!flag) 
//	{
//		cout << "NULL";
//	}
//	return 0;
//}
//
