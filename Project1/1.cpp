#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
const int max_position = 100000 + 10;
int n, q,m;
struct Pos
{
    int index;
    int num;
}pos[max_position];
bool Cmp(Pos x, Pos y)
{
    return x.num < y.num;
}
void HalfDivide()
{
    int left = 1, right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (m > pos[mid].num) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    if (pos[left].num == m)
        cout << pos[left].index << endl;
    else
        cout << "0" << endl;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        pos[i].index = i;
        cin >> pos[i].num;
    }
    sort(pos + 1, pos + 1 + n, Cmp);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> m;
        HalfDivide();
    }
    return 0;

}
