#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
char tree[1050];
int p2[11] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };
int main() 
{
    cin >> n; 
    
    for (int i = 1; i <= p2[n]; i++) 
    {
        char t;
        cin >> t;
        tree[i] = t - '0';
        if (tree[i] == 0)
            printf("B");
        else if 
            (tree[i] == 1)printf("I");
        else
            printf("F");
        for (int k = 1; k < 11; k++)
        {
            if (i % p2[k] == 0) 
            {
                if (tree[i] != tree[i - p2[k - 1]])
                    tree[i] = 2;
                if (tree[i] == 0)
                    printf("B");
                else if (tree[i] == 1)
                    printf("I");
                else 
                    printf("F");
            }
        }
    }
    return 0;
}





