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

//31.5.21.-*7.+@
//31.5.21.++@
int main()
{
    Array<int, 100>  class_array_char;
    bool isContinue = false;
    for (int i = 0; i < class_array_char.m_size; i++)
    {
        char t;
        scanf("%c", &t);
        if (t == '.')
        {
            isContinue = false;
            continue;
        }
        if (t == '@')
        {
            isContinue = false;
            break;
        }
        
        if (t >= '0' && t <= '9')
        {
            if (isContinue)
            {
                class_array_char.Push(class_array_char.Pop()*10 + t - '0');
            }
            else
            {
                class_array_char.Push(t - '0');
            }
            isContinue = true;
        }
        else
        {
            isContinue = false;
            if (t == '+')
            {
                int int_2 = class_array_char.Pop();
                int int_1 = class_array_char.Pop();
                class_array_char.Push(int_1 + int_2);
            }if (t == '-')
            {
                int int_2 = class_array_char.Pop();
                int int_1 = class_array_char.Pop();
                class_array_char.Push(int_1 - int_2);
            }if (t == '*')
            {
                int int_2 = class_array_char.Pop();
                int int_1 = class_array_char.Pop();
                class_array_char.Push(int_1 * int_2);
            }if (t == '/')
            {
                int int_2 = class_array_char.Pop();
                int int_1 = class_array_char.Pop();
                class_array_char.Push(int_1 / int_2);
            }
        }
    }
    printf("%d", class_array_char.array[0]);
    return 0;
}




