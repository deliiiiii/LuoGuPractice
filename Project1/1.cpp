#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <queue>
#include<algorithm>
#include<cstring>
using namespace std; 

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
const int max_n = 1 * 1e4 + 10;
const int max_m = 5 * 1e5 + 10;
const int max_int = 0x7fffffff;
int ans[max_n];
bool visited[max_n];
int n, m, s;

typedef int KeyType;
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef struct {
	int key;
	char others[20];
} DotNode;                       //顶点类型定义
typedef struct ArcNode {            //边
	int index_target_dot;                     //到哪个顶点的编号
	int distance;                   //到该顶点的距离
	struct ArcNode* nextarc;	    //下一个边结点指针
} ArcNode;
typedef struct VNode {				//头结点及其数组类型定义
	DotNode data;       	        //顶点信息
	ArcNode* firstarc;      	    //指向第一条边
} VNode, AdjList[max_n];
typedef  struct ALGraph 
{                   
	AdjList dots;     	            //头结点数组
	int vexnum, arcnum;   	        //顶点数、弧数
	GraphKind  kind;                //图的类型
} ALGraph, * ALGraphPointer;
ALGraph G ;
DotNode V[max_n];
KeyType VR[max_m][3];
int CreateGraph(ALGraph& m_G, DotNode m_V[], KeyType m_VR[][3])
{
    m_G.vexnum = 0;                                           //图的边和顶点数赋值为0
    m_G.arcnum = 0;
    for (int i = 1; m_V[i].key != -1; i++)
    {
        //for (int j = 0; j < i; j++)
        //{
        //    if (m_V[j].key == m_V[i].key) return ERROR;         //关键字重复
        //}
        m_G.vexnum++;
        //if (m_G.vexnum > MAX_VERTEX_NUM)return ERROR;         //边数超过最大值
        m_G.dots[i].firstarc = NULL;
        m_G.dots[i].data.key = m_V[i].key;
        //strcpy(m_G.dots[i].data.others, m_V[i].others);
    }
    for (int i = 1; m_VR[i][0] != -1; i++)
    {
        int n1 = m_VR[i][0], n2 = m_VR[i][1];
        //for (; n1 < m_G.vexnum; n1++)
        //{
        //    if (m_G.dots[n1].data.key == m_VR[i][0])
        //    {
        //        break;                                      //找到了顶点
        //    }
        //}
        ////if (n1 == m_G.vexnum) return ERROR;
        //for (; n2 < m_G.vexnum; n2++)
        //{
        //    if (m_G.dots[n2].data.key == m_VR[i][1])
        //    {
        //        break;                                      //找到了顶点
        //    }
        //}
        //if (n2 == m_G.vexnum) return ERROR;

        m_G.arcnum++;
        //if (m_G.arcnum > 100)return ERROR;
        if (n1 == n2)continue;
        int judge = 1;
        
        if (judge == 0)continue;
        if (!m_G.dots[n1].firstarc)                       //没有边相连
        {
            m_G.dots[n1].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
            m_G.dots[n1].firstarc->nextarc = NULL;
            m_G.dots[n1].firstarc->index_target_dot = n2;
            m_G.dots[n1].firstarc->distance = m_VR[i][2];
        }
        else                                                //有边相连
        {
            for (ArcNode* this_arc = m_G.dots[n1].firstarc; this_arc; this_arc = this_arc->nextarc)
            {
                if (this_arc->index_target_dot == n2)       //重复边
                {
                    if (this_arc->distance > m_VR[i][2])
                    {
                        this_arc->distance = m_VR[i][2];
                    }
                    judge = 0;
                    break;
                }
            }
            ArcNode* temp = m_G.dots[n1].firstarc;
            while (temp)
            {
                if (temp->index_target_dot == n2)
                {
                    judge = 0;
                    break;                                  //不允许自成环
                }
                temp = temp->nextarc;
            }
            if (judge == 1)
            {
                temp = (ArcNode*)malloc(sizeof(ArcNode));
                temp->nextarc = m_G.dots[n1].firstarc;
                temp->index_target_dot = n2;
                temp->distance = m_VR[i][2];
                m_G.dots[n1].firstarc = temp;
            }
        }
        //if (judge == 1)
        //{
        //    if (!m_G.dots[n2].firstarc)                       //没有边相连
        //    {
        //        m_G.dots[n2].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
        //        m_G.dots[n2].firstarc->nextarc = NULL;
        //        m_G.dots[n2].firstarc->index_target_dot = n1;
        //        m_G.dots[n2].firstarc->distance = m_VR[i][2];
        //    }
        //    else                                                //有边相连
        //    {
        //        ArcNode* temp = m_G.dots[n2].firstarc;
        //        while (temp)
        //        {
        //            if (n1 == n2)
        //            {
        //                judge = 0;
        //                break;                                  //不允许自成环
        //            }
        //            temp = temp->nextarc;
        //        }
        //        if (judge == 1)
        //        {
        //            temp = (ArcNode*)malloc(sizeof(ArcNode));
        //            temp->nextarc = m_G.dots[n2].firstarc;
        //            temp->index_target_dot = n1;
        //            temp->distance = m_VR[i][2];
        //            m_G.dots[n2].firstarc = temp;
        //        }
        //    }
        //}
    }
    return 1;
}
int main() 
{
	//memset(ans, max_int, sizeof(ans));
	//memset(visited, false, sizeof(visited));
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = max_int;
        visited[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        V[i].key = i;
    }
    V[n+1].key = -1 , strcpy(V[n+1].others ,"null");
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &VR[i][0] ,& VR[i][1], & VR[i][2]);
    }
    VR[m+1][0] = VR[m+1][1] = VR[m+1][2] = -1;
    CreateGraph(G, V, VR);
    ans[s] = 0;
    while (!visited[s])
    {
        visited[s] = true;
        for (ArcNode* this_arc = G.dots[s].firstarc; this_arc; this_arc = this_arc->nextarc)
        {
            ans[this_arc->index_target_dot] = min(ans[this_arc->index_target_dot], ans[s] + this_arc->distance);
        }
        int my_min = max_int;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && ans[i] < my_min)
            {
                my_min = ans[i];
                s = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
	return 0;
}