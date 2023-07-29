//#include <iostream>
//using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

long long n, f[20][20];
long long dfs(int x, int y)
{
    if (x == 0) return 1;
    if (f[x][y] != 0) return f[x][y];
    if (y > 0) f[x][y] += dfs(x, y - 1);
    f[x][y] += dfs(x - 1, y + 1);
    return f[x][y];
}
int main()
{
    scanf("%lld", &n);
    printf("%lld", dfs(n, 0));
    return 0;
}