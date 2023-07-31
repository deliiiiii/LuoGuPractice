#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
const int max_n = 1e5 + 10;
int n, m;
struct Node
{
    Node* next;
    Node* last;
    int index;
}stu[max_n];
Node* start = (Node*)malloc(sizeof(Node));
void Cut(int ID)
{
    
    Node* cut = &stu[ID];
    if (cut->last)
    {
        cut->last->next = cut->next;
        cut->next->last = cut->last;
        cut->last = cut->next = NULL;
    }
}
void Add(int relayID, int addedID, bool isRight)
{
    Node* relay = &stu[relayID], * added = &stu[addedID];
    if (!isRight)
    {
        added->next = relay;
        added->last = relay->last;
        added->last->next = added;
        relay->last = added;
    }
    else
    {
        added->next = relay->next;
        added->last = relay;
        relay->next = added;
        added->next->last = added;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        stu[i].index = i;
    }
    Node* p_stu1 = &stu[1];
    start->index = 0;
    start->next = p_stu1;
    start->last = p_stu1;
    p_stu1->next = start;
    p_stu1->last = start;
    for (int i = 2; i <= n; i++)
    {
        int ii, p;
        cin >> ii >> p;
        Add(ii,i, p);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int ii;
        cin >> ii;
        Cut(ii);
    }
    Node* tranverse = start->next;
    while (tranverse != start)
    {
        cout << tranverse->index << " ";
        tranverse = tranverse->next;
    }
    return 0;

}
