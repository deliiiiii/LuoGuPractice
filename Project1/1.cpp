#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
typedef unsigned long long ull;
ull base = 131;
ull a[10010];
char s[10010];
int n, ans = 1;
ull mod = 212370440130137957ll;
ull SetHash(char s[])
{
    int len = strlen(s);
    ull ans = 0;
    for (int i = 0; i < len; i++)
        ans = (ans * base + (ull)s[i])*114514 % mod;
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        a[i] = SetHash(s);
    }
    sort(a , a + n);
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
            ans++;
    }
        
    cout << ans;
    return 0;
}
