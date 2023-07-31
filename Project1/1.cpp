#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int max_n = 1 * 1e5 + 10;
int work()
{
	int count = 0;
	char ch;
	while( cin >> ch)
	{
		if (ch == ')')
			return count;
		else if (ch == '(')
			count += work();
		else if (ch == '|')
			return max(count, work());
		else
			count++;
	}
	return count;
}

int main()
{
	cout << work();
	return 0;
}