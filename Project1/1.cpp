#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include<queue>
using namespace std;
const int max_team = 1e3 + 10;
const int max_teamer = 1e3 + 10;
queue<int>queue_index_team;
queue<int>queue_index_teamer[max_team];
int count_team, count_teamer;
int index_teamer[max_team][max_teamer];
int myTeamIndex[1000000];
void Clear()
{
    while (!queue_index_team.empty())
        queue_index_team.pop();
    for (int i = 0; i < max_team; i++)
    {
        while (!queue_index_teamer[i].empty())
            queue_index_teamer[i].pop();
    }
}
int main()
{
    int count_test = 1;
    while (1)
    {
        scanf("%d", &count_team);
        if (count_team == 0)
            return 0;
        Clear();
        cout << "Scenario #" << count_test << endl;
        for (int i = 1; i <= count_team; i++)
        {
            cin >> count_teamer;
            for (int j = 1; j <= count_teamer; j++)
            {
                cin >> index_teamer[i][j];
                myTeamIndex[index_teamer[i][j]] = i;
            }
        }
        
        while (1)
        {
            char cata[20];
            scanf("%s", cata);
            if (cata[0] == 'S')
            {
                count_test++;
                cout << endl;
                break;
            }
            if (cata[0] == 'E')
            {
                int added;
                scanf("%d", &added);
                if (queue_index_teamer[myTeamIndex[added]].empty())
                {
                    queue_index_team.push(myTeamIndex[added]);
                }
                queue_index_teamer[myTeamIndex[added]].push(added);
            }
            if (cata[0] == 'D')
            {
                cout << queue_index_teamer[queue_index_team.front()].front() << endl;
                queue_index_teamer[queue_index_team.front()].pop();
                if (queue_index_teamer[queue_index_team.front()].empty())
                {
                    queue_index_team.pop();
                }
            }
        }
    }
    return 0;
}
