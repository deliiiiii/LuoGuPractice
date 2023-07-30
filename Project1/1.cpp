#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

string a, b;
void DFS(string x, string y) {
	if (!(int)y.size()) return;
	int pos = x.find(y[0]);
	DFS(x.substr(0, pos), y.substr(1, pos));
	DFS(x.substr(pos + 1), y.substr(pos + 1));
	cout << y[0];
}
int main() 
{
	cin >> a >> b;
	DFS(a, b);
	return 0;
}








