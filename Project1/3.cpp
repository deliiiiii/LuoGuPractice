#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>

#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;

map<string, int>sum;//次数
map<string, bool>flag;//1:想背
int ans1, ans2, target_word, count_word_in_article;
string s[100005], temp_s;
int main()
{
	cin >> target_word;
	for (int i = 1; i <= target_word; i++)
	{
		cin >> temp_s;
		flag[temp_s] = 1;
	}
		
	cin >> count_word_in_article;
	int l = 1;
	for (int i = 1; i <= count_word_in_article; i++)
	{
		cin >> s[i];
		if (flag[s[i]])//要背
		{
			sum[s[i]]++;
		}
		if (sum[s[i]] == 1)//新出现
		{
			ans1++;
			ans2 = i - l + 1;//更新长度
		}
		while (l <= i)
		{
			if (!flag[s[l]])//不要背
			{
				l++; 
				continue; 
			}
			if (sum[s[l]] >= 2)//重复出现
			{
				sum[s[l]]--;
				l++; 
				continue;
			}
			break;
		}
		ans2 = min(ans2, i - l + 1);//更新
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}