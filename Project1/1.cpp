#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char>num_1;
vector<char>num_2;
void ReverseAndPrint_0()
{
    std::reverse(num_1.begin(), num_1.end());
    if (num_1.size() == 1 && num_1[0] == '0')
    {
        cout << '0';
    }
    else
    {
        bool find1 = false;
        int size_init = num_1.size();
        for (int i = 0, count = 0; count < size_init; i++, count++)
        {
            if (num_1[i] == '0' && !find1)
            {
                num_1.erase(num_1.begin());
                i--;
            }
            else
            {
                find1 = true;
                break;
            }
        }
        for (int i = 0; i < num_1.size(); i++)
        {
            cout << num_1[i];
        }
    }
}
void ReverseAndPrint_1()
{
    if (num_2.size() == 1 && num_2[0] == '0')
    {
        cout << '0';
        return;
    }
    bool find1 = false;
    int size_init = num_2.size();
    for (int i = 0, count = 0; count < size_init; i++, count++)
    {
        if (num_2[i] == '0' && !find1)
        {
            num_2.erase(num_2.begin());
            i--;
        }
        else
        {
            find1 = true;
            break;
        }
    }
    std::reverse(num_2.begin(), num_2.end());
    for (int i = 0; i < num_2.size(); i++)
    {
        cout << num_2[i];
    }
}
void ReverseAndPrint_2()
{
    std::reverse(num_2.begin(), num_2.end());
    if (num_2.size() == 1 && num_2[0] == '0')
    {
        cout << '0';
    }
    else
    {
        bool find1 = false;
        int size_init = num_2.size();
        for (int i = 0, count = 0; count < size_init; i++, count++)
        {
            if (num_2[i] == '0' && !find1)
            {
                num_2.erase(num_2.begin());
                i--;
            }
            else
            {
                find1 = true;
                break;
            }
        }
        for (int i = 0; i < num_2.size(); i++)
        {
            cout << num_2[i];
        }
    }
}
int main()
{
    char t;
    char speci;
    int state = 0;
    t = getchar();
    int times = 0;
    while (t != EOF && ((t >= '0' && t <= '9') || t == '.' || t == '/' || t == '%'))
    {
        times++;
        if (times > 100)  return-1;
        if (t == '.')
        {
            speci = t;
            state = 1;
            break;
        }
        if (t == '/')
        {
            speci = t;
            state = 2;
            break;
        }
        if (t == '%')
        {
            speci = t;
            state = 3;
            break;
        }
        num_1.push_back(t);
        t = getchar();
    }
    ReverseAndPrint_0();

    switch (state)
    {

    case 0:
    {
        break;
    }
    case 1:
    {
        cout << speci;
        t = getchar();
        times = 0;
        while (t != EOF && t >= '0' && t <= '9')
        {
            times++;
            if (times > 100)  return-1;
            num_2.push_back(t);
            t = getchar();
        }
        ReverseAndPrint_1();
        break;
    }
    case 2:
    {
        cout << speci;
        t = getchar();
        times = 0;
        while (t != EOF && t >= '0' && t <= '9')
        {
            times++;
            if (times > 100)  return-1;
            num_2.push_back(t);
            t = getchar();
        }
        ReverseAndPrint_2();
        break;
    }
    case 3:
    {
        cout << speci;
        break;
    }
    default: break;
    }
    return 0;
}




