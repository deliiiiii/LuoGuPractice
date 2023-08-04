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
    int index, k, score;
};
Competitor init[2 * max_n];
Competitor mid1[max_n], mid2[max_n];
Competitor final[2 * max_n];
int per_N, R, Q;
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
    return x.index < y.index;
}
void work()
{
    for (int i = 1; i <= per_N; i++)
    {
        if (init[2 * i - 1].k > init[2 * i].k)
        {
            init[2 * i - 1].score++, mid1[i] = init[2 * i - 1], mid2[i] = init[2 * i];
        }
        else
        {
            init[2 * i].score++, mid1[i] = init[2 * i], mid2[i] = init[2 * i - 1];
        }
    }

    int i = 1, j = 1, k = 1;
    while (i <= per_N && j <= per_N)
    {
        if (cmp(mid1[i], mid2[j]))
        {
            final[k] = mid1[i];
            k++, i++;
        }

        else
        {
            final[k] = mid2[j];
            k++, j++;
        }
    }
    while (i <= per_N)
    {
        final[k] = mid1[i];
        k++, i++;
    }
    while (j <= per_N)
    {
        final[k] = mid2[j];
        k++, j++;
    }
    for (int i = 1; i <= 2 * per_N; i++)
    {
        init[i] = final[i];
    }
}
int main()
{
    per_N = read(), R = read(), Q = read();
    for (int i = 1; i <= 2 * per_N; i++)
        init[i].index = i, init[i].score = read();
    for (int i = 1; i <= 2 * per_N; i++)
        init[i].k = read();
    sort(init + 1, init + 1 + 2 * per_N, cmp);
    for (int i = 0; i < R; i++)
        work();
    printf("%d", init[Q].index);
    return 0;
}