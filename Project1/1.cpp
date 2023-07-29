#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int target_score = 11;
int deltaScore = 2;
int score_1 = 0,score_2 = 0;
int roundScore_1 = 0, roundScore_2 = 0;
vector<char>input;
int absDelta(int a, int b)
{
    return a > b ? a - b : b - a;
}
bool LowDeltaScore()
{
    return absDelta(score_1, score_2) < 2;
}
void Execute()
{
    char t;
    scanf("%c", &t);
    input.push_back(t);
    while (t != EOF)
    {
        if (t == '\n')
        {
            scanf("%c", &t);
            input.push_back(t);
            continue;
        }
        if (t == 'W')score_1++;
        if (t == 'L')score_2++;
        if (t == 'E')
        {
            cout << score_1 << ":" << score_2 << endl;
            break;
        }
        if (score_1 < target_score && score_2 < target_score
            ||
            ((score_1 >= target_score || score_2 >= target_score) && LowDeltaScore())
            )
        {
        }
        else
        {
            cout << score_1 << ":" << score_2 << endl;
            score_1 > score_2 ? roundScore_1++ : roundScore_2++;
            score_1 = score_2 = 0;
        }
        scanf("%c", &t);
        input.push_back(t);
    }
}
void Execute_2()
{
    char t;
    t = input[0];
    input.erase(input.begin());
    while (t != EOF)
    {
        if (t == '\n')
        {
            t = input[0];
            input.erase(input.begin());
            continue;
        }
        if (t == 'W')score_1++;
        if (t == 'L')score_2++;
        if (t == 'E')
        {
            cout << score_1 << ":" << score_2 << endl;
            break;
        }
        if (score_1 < target_score && score_2 < target_score
            ||
            ((score_1 >= target_score || score_2 >= target_score) && LowDeltaScore())
            )
        {
        }
        else
        {
            cout << score_1 << ":" << score_2 << endl;
            score_1 > score_2 ? roundScore_1++ : roundScore_2++;
            score_1 = score_2 = 0;
        }
        t = input[0];
        input.erase(input.begin());
    }
}
int main()
{
    Execute();
    cout << endl;
    score_1 = score_2 = 0;
    roundScore_1 = roundScore_2 = 0;
    target_score = 21;
    Execute_2();
    return 0;
}




