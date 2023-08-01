#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int max_n = 1 * 1e5 + 10;



std::vector<int> nearChart[max_n];
int n, m;
bool visited[max_n];
queue<int> q;

void dfs(int x, int cur) 
{
	visited[x] = true;
	cout << x << " ";
	if (cur == n) 
		return;
	for (int i = 0; i < nearChart[x].size(); i++)
		if (!visited[nearChart[x][i]]) 
			dfs(nearChart[x][i], cur + 1);
}

void bfs(int x) 
{
	visited[x] = true;
	q.push(x);
	while (!q.empty()) 
	{
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int i = 0; i < nearChart[temp].size(); i++)
		{
			if (!visited[nearChart[temp][i]])
			{
				visited[nearChart[temp][i]] = true;
				q.push(nearChart[temp][i]);
			}
		}
	}
}

int main() 
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) 
	{
		int u, v;
		cin >> u >> v;
		nearChart[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) 
		sort(nearChart[i].begin(), nearChart[i].end());
	memset(visited, false, sizeof(visited));
	dfs(1, 0);
	cout << endl;
	memset(visited, false, sizeof(visited));
	bfs(1);
	cout << endl;
	return 0;
}