#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
const int max_n = 5e6 + 10;
int n, p;
int score[max_n];
int t[max_n];
int sum[max_n];
int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        t[i] = sum[i] = 0;
        cin >> score[i];
    }
    t[n + 1] = sum[n + 1] = 0;
    for (int i = 1; i <= p; i++)
    {
        int s1, s2,added;
        cin >> s1 >> s2 >> added;
        t[s1] += added;
        t[s2 + 1] -= added;
    }
    int min = 114514;
    int last_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        last_sum += t[i];
        score[i] += last_sum;
        if (score[i] < min) 
            min = score[i];
    }
    cout << min;
    return 0;

}
