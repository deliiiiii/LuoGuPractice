#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
const int max_n = 100 + 10;
const int max_m = 100 + 10;
int n, m;
int watered[max_n];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        watered[i] = 0;
    }
    for(int i=0;i<m;i++)
    {
        int day1, day2;
        cin >> day1 >> day2;
        for (int j = day1; j <= day2; j++)
        {
            watered[j] ++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (watered[i] != 1)
        {
            cout << i << " " << watered[i];
            return 0;
        }
    }
    cout << "OK";
    return 0;

}
