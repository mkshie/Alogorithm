#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;

    cin >> str1 >> str2;

    int str1_size = str1.size();
    int str2_size = str2.size();

    if (str1[0] == str2[0])
        dp[0][0] = 1;

    for (int i = 1; i < str1_size; i++)
    { // 초기값 세팅
        int num = (str1[i] == str2[0]) ? 1 : 0;
        dp[i][0] = max(dp[i - 1][0], num);
    }
    for (int i = 1; i < str2_size; i++)
    {
        int num2 = (str2[i] == str1[0]) ? 1 : 0;
        dp[0][i] = max(dp[0][i - 1], num2);
    }
    for (int j = 1; j < str2_size; j++)
    {
        for (int i = 1; i < str1_size; i++)
        {
            int num = max(dp[i - 1][j], dp[i][j - 1]);
            if (str1[i] == str2[j])
            {
                dp[i][j] = max(num, dp[i - 1][j - 1] + 1);
            }
            else
            {
                dp[i][j] = max(num, dp[i - 1][j - 1]);
            }
        }
    }
    int search_num = dp[str1_size - 1][str2_size - 1];
    cout << search_num << "\n";
    if (dp[str1_size - 1][str2_size - 1] == 0)
        return 0;
    else
    {
        stack<char> answer;
        int i = str1_size - 1;
        int j = str2_size - 1;
        while (i >=0 && j >=0)
        {
            if(str1[i] == str2[j]){
                answer.push(str1[i]);
                i--;
                j--;
            }
            else if(dp[i-1][j] == dp[i][j]){
                i--;
            }
            else{
                j--;
            }
        }
        while(!answer.empty()){
            cout << answer.top();
            answer.pop();
        }
        cout << "\n";
    }
}
