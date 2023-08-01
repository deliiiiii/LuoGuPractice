#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int max_n = 1 * 1e6 + 10;
struct Node
{
	int index;
	int value;
}nums[max_n];
vector<Node>vector_ascend;
//vector<Node>vector_descend;
int n, k;

void Clear()
{
	while (vector_ascend.size() != 0)
	{
		vector_ascend.pop_back();
	}
}
void Add(bool isAscend , Node node)
{
	if (isAscend)
	{
		while (!vector_ascend.empty() && vector_ascend[vector_ascend.size() - 1].value > node.value)
		{
			vector_ascend.pop_back();
		}
		vector_ascend.push_back(node);
	}
	else
	{
		while (!vector_ascend.empty() && vector_ascend[vector_ascend.size() - 1].value < node.value)
		{
			vector_ascend.pop_back();
		}
		vector_ascend.push_back(node);
	}
}
void Remove(int cur_index)
{
	while (!vector_ascend.empty() && vector_ascend[0].index < cur_index)
	{
		vector_ascend.erase(vector_ascend.begin());
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		nums[i].index = i;
		cin >> nums[i].value;
	}
	Clear();
	for (int i = 1; i <= k; i++)
	{
		Add(true, nums[i]);
	}
	cout << vector_ascend[0].value << " ";
	for (int i = 1; i + k <= n; i++)
	{
		Remove(i+1);
		Add(true, nums[i+k]);
		cout << vector_ascend[0].value << " ";
	}
	cout << endl;
	Clear();
	for (int i = 1; i <= k; i++)
	{
		Add(false, nums[i]);
	}
	cout << vector_ascend[0].value << " ";
	for (int i = 1; i + k <= n; i++)
	{
		Remove(i + 1);
		Add(false, nums[i + k]);
		cout << vector_ascend[0].value << " ";
	}
	return 0;
}