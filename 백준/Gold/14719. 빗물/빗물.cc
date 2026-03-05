#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <stack>
#include <deque>

using namespace std;

vector<int> arr;
deque<int> dq;
int H, W; // 세로 , 가로
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> W;

    int answer = 0;

    for (int i = 0; i < W; i++)
    {
        int num;

        cin >> num;

        if (dq.empty())
        {
            if (num == 0)
            {
                continue;
            }
            else
            {
                dq.push_back(num);
            }
        }
        else
        {
            // 들어온값이 같거나 크면 계산 시작
            if (dq.front() <= num)
            {
                // 계산 시작해야함
                dq.push_back(num);
                int front_num = dq.front();
                dq.pop_front();
                while (dq.size() != 1)
                {
                    answer += front_num - dq.front();
                    dq.pop_front();
                }
            }
            else if (dq.back() < num)
            {
                // 바로 이전보다 클 경우에도 계산 시작
                // 이때 더해준 경우 값을 수정해야함
                int size_check = 0;
                for (int j = dq.size() - 1; dq[j] < num; j--)
                {
                    answer += num - dq[j];
                    size_check++;
                    dq.pop_back();
                }
                for (int j = 0; j < size_check; j++)
                {
                    dq.push_back(num);
                }
                dq.push_back(num);
            }
            else
            {
                dq.push_back(num);
            }
        }
    }

    cout << answer << "\n";
}