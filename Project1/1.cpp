#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <class T, int size>
class Array
{
public:
    Array()
    {
        m_count = 0; 
        m_size = size;
    }
    void Push(T elem) 
    {
        array[m_count] = elem;
        m_count++;
    }
    T Pop()
    {
        if (m_count == 0)return -1;
        return array[(m_count--) - 1];
    }
    void display()
    {
        int i;
        for (i = 0; i < m_count; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    public:
        T array[size];
        int m_count;
        int m_size;
}; 
Array<long long int,5>  class_array_int;
//6+2*3*4+4
int main()
{
    bool isContinue = false,isMultiply = false;
    long long int result = 0;
    int m = 10000;
    for (int i = 0; ; )
    {
        char t;
        scanf("%c", &t);
        if (t == EOF || t == '\n')
        {
            if (isMultiply)
            {
                long long int int_2 = class_array_int.Pop();
                long long int int_1 = class_array_int.Pop();
                class_array_int.Push(int_2 * int_1 % m);
            }
            result += class_array_int.Pop();
            result %= m;
            break;
        }
        if (t >= '0' && t <= '9')
        {
            if (isContinue)
            {
                class_array_int.Push(class_array_int.Pop()*10 + t - '0');
            }
            else
            {
                class_array_int.Push(t - '0');
            }
            isContinue = true;
        }
        else
        {
            isContinue = false;
            if (t == '+')
            {
                if (isMultiply)
                {
                    long long int int_2 = class_array_int.Pop();
                    long long int int_1 = class_array_int.Pop();
                    class_array_int.Push(int_2 * int_1 % m);
                }
                result += class_array_int.Pop();
                result %= m;
                isMultiply = false;
                continue;
            }
            if (t == '*')
            {
                if (isMultiply)
                {
                    long long int int_2 = class_array_int.Pop();
                    long long int int_1 = class_array_int.Pop();
                    class_array_int.Push(int_2 * int_1 % m);
                }
                isMultiply = true;
            }
        }
    }
    printf("%d", result);
    return 0;
}




