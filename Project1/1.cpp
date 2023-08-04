#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <queue>
#include<algorithm>
#include<cstring>
using namespace std; 

const int max_n = 5 * 1e5 + 10;
struct node
{
    int val, num;
}a[max_n];
int n;
long long ans = 0;
int c[max_n];
void add(int x, int k)
{
    for (int i = x; i <= n; i += i & (-i)) 
        c[i] += k;
}
int query(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= i & (-i))
        sum += c[i];
    return sum;
}
int cmp(node x, node y)
{ 
    if (x.val == y.val) 
        return x.num > y.num; 
    return x.val > y.val; 
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].val);
        a[i].num = i;
    }
    stable_sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        add(a[i].num, 1);
        ans += query(a[i].num - 1);
    }
    cout << ans << endl;
    return 0;
}