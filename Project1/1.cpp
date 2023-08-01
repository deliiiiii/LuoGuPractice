#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

#include<cstring>
using namespace std;
const int max_n = 1 * 1e2 + 10;



struct TreeNode
{
    int index;
    TreeNode* left;
    TreeNode* right;
    TreeNode* father;
};
TreeNode* node[max_n];
void AddArc(int n1, int n2)
{
    if (!node[n1]->left)
    {
        node[n1]->left = node[n2];
        node[n2]->father = node[n1];
    }
    else
    {
        node[n1]->right = node[n2];
        node[n2]->father = node[n1];
    }
}
int Btdepth(TreeNode* T) {
    if (T == NULL)
        return 0;
    int ldep = Btdepth(T->left);
    int rdep = Btdepth(T->right);
    if (ldep > rdep)
        return ldep + 1;
    else
        return rdep + 1;
}
int  my_count[100];
int max_width = -1;

void FindWidth(TreeNode* T, int k)
{
    if (T == NULL)
        return;
    my_count[k]++;
    if (max_width < my_count[k])
        max_width = my_count[k];
    FindWidth(T->left, k + 1);
    FindWidth(T->right, k + 1);
}

//MAX即为所求宽度
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == p || root == q || !root)return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (!left && !right)return NULL;
    else if (left && !right)return left;
    else if (right && !left)return right;

    return root;
}

int n;
int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        node[i] = (TreeNode*)malloc(sizeof(TreeNode));
        node[i]->index = i;
        node[i]->left = NULL;
        node[i]->right = NULL;
        node[i]->father = NULL;
    }
    int n1, n2;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> n1 >> n2;
        AddArc(n1, n2);
    }
    cin >> n1 >> n2;
    int target = lowestCommonAncestor(node[1], node[n1], node[n2])->index;
    int ans = 0;
    TreeNode* t1 = node[n1];
    TreeNode* t2 = node[n2];
    while (t1->index != target)
    {
        t1 = t1->father;
        ans += 2;
    }
    while (t2->index != target)
    {
        t2 = t2->father;
        ans += 1;
    }
    cout << Btdepth(node[1]) << endl;
    FindWidth(node[1], 1);
    cout << max_width << endl;
    cout << ans;
    return 0;
}