#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include<stack>
using namespace std;
const int max_n = 3 * 1e6 + 10;
struct Node
{
    int index;
    int value;
}nums[max_n];

stack<Node>stack_nums;
int n;
int ans[max_n];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        nums[i].index = i;
        cin >> nums[i].value;
        while (!stack_nums.empty() && stack_nums.top().value < nums[i].value)
        {
            ans[stack_nums.top().index] = i;
            stack_nums.pop();
        }
        stack_nums.push(nums[i]);
    }
    while (!stack_nums.empty())
    {
        ans[stack_nums.top().index] = 0;
        stack_nums.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;

}
