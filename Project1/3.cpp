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
int topo[max_n][max_n], level[max_n];// topo[i][j] == 1 等价于 j 级别≥ i 
bool station[max_n], cut[max_n]; //判断本站有无火车停靠；是否已经删除这个点

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        memset(station, false, sizeof(station)); //每条线路初始化
        int count_stopped_station;
        scanf("%d", &count_stopped_station);
        for (int j = 1; j <= count_stopped_station; j++)
        {
            scanf("%d", &index_station[j]);
            station[index_station[j]] = true;//读取停靠数据
        }
        for (int j = index_station[1]; j <= index_station[count_stopped_station]; j++) //枚举每个站点
        {
            if (station[j])//有火车停靠本站点
            {
                continue;
            }
            //else 没有火车停靠本站点
            for (int k = 1; k <= count_stopped_station; k++)
            {
                if (topo[j][index_station[k]] == 0)
                {
                    topo[j][index_station[k]] = 1;
                    level[index_station[k]]++;
                }
            }
        }
    }

    memset(cut, false, sizeof(cut));
    int ans = 0, count_top = 0;

    do
    {
        count_top = 0;
        for (int i = 1; i <= n; i++)
        {
            if (level[i] == 0 && !cut[i])
            {
                cut[i] = true;
                count_top++;
                t[count_top] = i;
            }
        }
        for (int i = 1; i <= count_top; i++)
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
    } while (count_top != 0);

    cout << ans - 1 << endl; // ans 会多加一次
    return 0;
}