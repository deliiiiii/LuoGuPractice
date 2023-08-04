#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

const int max_n = 1 * 1e5 + 10;
int n;
struct node {
	int index, m_height;
};
stack<node> stac;
int height[max_n], ans;
int myleft[max_n], myright[max_n];
void clean()
{
	while (!stac.empty())
		stac.pop();
}
int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> height[i];
	}
	for (i = 1; i <= n; i++)
	{
		while (!stac.empty() && stac.top().m_height < height[i])
			stac.pop();
		if (!stac.empty())
			myleft[i] = stac.top().index;
		else myleft[i] = 0;
		node t;
		t.m_height = height[i];
		t.index = i;
		stac.push(t);
	}
	clean();
	for (i = n; i >= 1; i--)
	{
		while (!stac.empty() && stac.top().m_height > height[i])
			stac.pop();
		if (!stac.empty())
			myright[i] = stac.top().index;
		else myright[i] = n + 1;
		node t;
		t.m_height = height[i];
		t.index = i;
		stac.push(t);
	}
	for (i = n; i >= 1; i--)
	{
		for (j = myleft[i] + 1; j < i; j++)
		{
			if (myright[j] > i)
			{
				ans = max(ans, i - j + 1);
				break;
			}
		}
		if (i <= ans) break;
	}
	cout << ans;
	return 0;
}