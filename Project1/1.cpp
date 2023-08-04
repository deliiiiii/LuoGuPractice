#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using std::sort;
using namespace std; 

const int max_n = 1 * 1e5 + 10;

struct Competitor 
{
    int n, k, score;
};
Competitor init[200050];
Competitor mid1[100050], c[100050];
Competitor final[200050];
int n, R, Q;
int read()
{
    int x = 0;
    char c = getchar();
    while (c > '9' || c < '0') 
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
bool cmp(Competitor x, Competitor y)
{
    if (x.score != y.score) 
        return x.score > y.score;
    return x.n < y.n;
}
void work()
{
    for (int i = 1; i <= n; i++)
    {
        if (init[2 * i - 1].k > init[2 * i].k)
        {
            init[2 * i - 1].score++, mid1[i] = init[2 * i - 1], c[i] = init[2 * i];
        }
        else
        {
            init[2 * i].score++, mid1[i] = init[2 * i], c[i] = init[2 * i - 1];
        }
    }
        
    int i = 1, j = 1, k = 1;
    while (i <= n && j <= n)
    {
        if (cmp(mid1[i], c[j]))
        {
            final[k] = mid1[i];
            k++, i++;
        }

        else
        {
            final[k] = c[j];
            k++, j++;
        }
    }
    while (i <= n)
    {
        final[k] = mid1[i];
        k++, i++;
    }
    while (j <= n)
    {
        final[k] = c[j];
        k++, j++;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        init[i] = final[i];
    }
}
int main()
{
    n = read(), R = read(), Q = read();
    for (int i = 1; i <= 2 * n; i++)
        init[i].n = i, init[i].score = read();
    for (int i = 1; i <= 2 * n; i++)
        init[i].k = read();
    sort(init + 1, init + 1 + 2 * n, cmp);
    for (int i = 0; i < R; i++)
        work();
    printf("%d", init[Q].n);
    return 0;
}