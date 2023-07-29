#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int>weight;
    vector<int>index_max_weight;
    int n;
    cin >> n;
    int inst, x;
    for (int i = 0; i < n; i++)
    {
        cin >> inst;
        switch (inst)
        {
            case 0:
            {
                cin >> x;
                
                
                weight.push_back(x);
                if (weight.size() == 1)
                {
                    index_max_weight.push_back(0);
                }
                else
                {
                    int size = index_max_weight.size();
                    if (x > weight[index_max_weight[index_max_weight.size() - 1]])
                    {
                        index_max_weight.push_back(size);
                    }
                    else
                    {
                        index_max_weight.push_back(index_max_weight[size - 1]);
                    }
                }
                break;
            }
            case 1:
            {   
                if (index_max_weight.size() == 0)
                {
                    continue;
                }
                weight.pop_back();
                index_max_weight.pop_back();
                break;
            }
            case 2:
            {
                if (index_max_weight.size() == 0)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << weight[index_max_weight[index_max_weight.size() - 1]] << endl;
                }
                break;
            }
        }
    }
    return 0;
}




