#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
const int max_n = 10000 + 10;
const int max_k = 1000 + 10;
int n, k;
int nums[max_n];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        nums[i] = 30001;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    int temp_k = 0;
    for (int i = 0; i < n; i++)
    {
        
        if (nums[i] == nums[i + 1])
        {
            continue;
        }
        temp_k++;
        if (temp_k == k) 
        {
            cout << nums[i];
            return 0;
        }
    }
    cout << "NO RESULT";
    return 0;
}
