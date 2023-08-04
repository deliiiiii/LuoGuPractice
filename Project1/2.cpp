#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int max_n = 1 * 1e4 + 10;
const int max_a = 2 * 1e4 + 10;
int n, temp, ans = 0;
priority_queue<int, vector<int>, greater<int> >q;
int main() 
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		q.push(temp);
	}
	while (q.size() >= 2) 
	{
		int num1 = q.top();
		q.pop();
		int num2 = q.top();
		q.pop();
		ans += num1 + num2;
		q.push(num1 + num2);
	}
	cout << ans << endl;
	return 0;
}