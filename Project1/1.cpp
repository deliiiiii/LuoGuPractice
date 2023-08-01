#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int max_n = 1 * 1e6 + 10;
int Work()
{
    string s;
    char c, temp;
    int num, ans = 0;
    while (cin >> c)
    {
        if (c == ']') break;//REPEAT n[]
        cin >> s >> num;
        if (c == 'R')
        {
            temp = getchar();//[
            ans += num * Work();
            temp = getchar();//¶Á']'ºó' '.
        }
        else if (c == 'B') 
        {
            temp = getchar(), ans -= num;
        }
        else if (c == 'F') 
        {
            temp = getchar(), ans += num;
        }
        if (temp == int(']'))
        {
            break;
        }
    }
    return ans;
}
int main()
{
    cout << abs(Work());
    return 0;
}