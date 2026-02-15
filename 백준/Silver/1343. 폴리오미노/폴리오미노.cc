#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dp(51);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 조금 별로긴해도 . 나올때까지 반복...

    string problem;

    cin >> problem;

    string answer = "";

    for (int i = 0; i < problem.size(); i++)
    {
        int cnt = 0;
        while (i < problem.size() && problem[i] != '.') // X 부분의 개수를 세고 넘김
        {
            cnt++;
            i++;
        }

        if (cnt != 0)
        {
            if (cnt % 4 == 0)
            {
                for (int j = 0; j < cnt; j++)
                    answer += 'A';
            }
            else if (cnt % 4 == 2)
            {
                for (int j = 0; j < cnt / 4; j++)
                    answer += "AAAA";

                answer += "BB";
            }
            else
            {
                cout << "-1\n";
                return 0;
            }
        }

        while (i < problem.size() && problem[i] == '.')
        {
            answer += ".";
            i++;
        }
        i--;
    }

    cout << answer << "\n";
    return 0;
}