#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> map;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
void Color3(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
    {
        return;
    }
    if (map[x][y] == 3 || map[x][y] == 1)
    {
        return;
    }
    if (map[x][y] == 0)
    {
        map[x][y] = 3;
    }
    for (int i = 1; i <= 4; i++)
    {
        Color3(x + dx[i], y + dy[i]);
    }
}
void Remove3_and_Color2()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 0)map[i][j] = 2;
            if (map[i][j] == 3)map[i][j] = 0;
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        map.push_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            map[i].push_back(t);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n-1 || j == n-1)
            {
                Color3(i, j);
            }
        }
    }
    Remove3_and_Color2();
    return 0;
}




