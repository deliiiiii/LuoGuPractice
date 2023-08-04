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

const int max_n = 500010;
int n, count_dot, index_start;
int head[max_n], index_dot[max_n], next_edge[max_n],  edge_length[max_n];
long long int ans = 0, my_distance[max_n];
void Add(int x, int y, int z)
{
	index_dot[++count_dot] = y;
	edge_length[count_dot] = z;
	next_edge[count_dot] = head[x];
	head[x] = count_dot;
}
void DFS(int x, int index_father)
{
	for (int dot_this = head[x]; dot_this; dot_this = next_edge[dot_this])
	{
		int y = index_dot[dot_this];
		int z = edge_length[dot_this];
		if (y == index_father) 
			continue;
		DFS(y, x);
		my_distance[x] = max(my_distance[x], my_distance[y] + z);
	}
	for (int dot_this = head[x]; dot_this; dot_this = next_edge[dot_this])
	{
		int y = index_dot[dot_this];
		int z = edge_length[dot_this];
		if (y == index_father) 
			continue;
		ans += my_distance[x] - (my_distance[y] + z);
	}
}

void Input()
{
	scanf("%d%d", &n, &index_start);
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		Add(x, y, z); 
		Add(y, x, z);
	}
}
int main()
{
	Input();
	DFS(index_start, 0);
	printf("%lld", ans);
	return 0;
}