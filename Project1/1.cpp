#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int max_n = 1 * 1e6 + 10;
#include<cstring>
int my_next[max_n];
int length_a, length_b, j=0;
char a[max_n], b[max_n];
int main()
{
    cin >> a + 1;
    cin >> b + 1;
    length_a = strlen(a + 1);
    length_b = strlen(b + 1);
    for (int i = 2; i <= length_b; i++)
    {
        while (j && b[i] != b[j + 1])
            j = my_next[j];
        if ((b+1)[j] == (b + 1)[i-1])
            j++;
        my_next[i] = j;
    }
    j = 0;
    for (int i = 1; i <= length_a; i++)
    {
        while (j > 0 && (b + 1)[j] != a[i])
            j = my_next[j];
        if ((b + 1)[j] == a[i])
            j++;
        if (j == length_b)
        { 
            cout << i - length_b + 1 << endl; 
            j = my_next[j];
        }
    }

    for (int i = 1; i <= length_b; i++)
        cout << my_next[i] << " ";
    return 0;
}