#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

#include<cstring>
using namespace std;
const int max_n = 1 * 1e6 + 10;
int n;


struct TreeNode
{
    int index;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* node[max_n];
void AddArc(int father,int n1, int n2)
{
    if (n1 != 0)
    {
        node[father]->left = node[n1];
    }
     
    if (n2 != 0)
    {
        node[father]->right = node[n2];
    }
    
}
int Btdepth(TreeNode * T) {
    if (T == NULL)
        return 0;
    int ldep = Btdepth(T->left);
    int rdep = Btdepth(T->right);
    if (ldep > rdep)
        return ldep + 1;
    else
        return rdep + 1;
}
int main() 
{
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        node[i] = (TreeNode*)malloc(sizeof(TreeNode));
        node[i]->index = i;
        node[i]->left = NULL;
        node[i]->right = NULL;
    }
    int n1, n2;
    for (int i = 1; i <= n; i++)
    {
        cin >> n1 >> n2;
        AddArc(i,n1, n2);
    }

    cout << Btdepth(node[1]) << endl;

	return 0;
}





