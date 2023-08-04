#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>

#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
const int max_n = 1 * 1e3 + 10;
int index_station[max_n], t[max_n];
int topo[max_n][max_n], level[max_n];// topo[i][j] == 1 等价于 j >= i 
bool station[max_n], cut[max_n]; //判断本站有无火车停靠；是否已经删除这个点

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        memset(station, false, sizeof(station)); //每条线路初始化
        int s;
        scanf("%d", &s);
        for (int j = 1; j <= s; j++)
        {
            scanf("%d", &index_station[j]);
            station[index_station[j]] = true;//读取停靠数据
        }
        for (int j = index_station[1]; j <= index_station[s]; j++) //枚举每个站点
        {
            if (station[j])//有火车停靠本站点
            {
                continue;
            }
            //else 没有火车停靠本站点
            for (int k = 1; k <= s; k++)
            {
                if (topo[j][index_station[k]] == 0)
                {
                    topo[j][index_station[k]] = 1; //k 的级别比 j 的级别高
                    level[index_station[k]]++;
                }
            }
        }
    }

    memset(cut, false, sizeof(cut)); //一开始没有任何火车停靠
    int ans = 0, top = 0;

    do
    { //不断删点、边
        top = 0;
        for (int i = 1; i <= n; i++)
        {
            if (level[i] == 0 && cut[i] == false)
            { //这个车站的级别为 0 且没有删去这个点
                cut[i] = true;
                top++;
                t[top] = i;
            }
        }
        for (int i = 1; i <= top; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (topo[t[i]][j] == 1)
                {
                    topo[t[i]][j] = 0;
                    level[j]--;
                }
            }
        }
        ans++;
    } while (top != 0);

    cout << ans - 1 << endl; // ans 会多加一次
    return 0;
}