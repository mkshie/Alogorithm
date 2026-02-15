#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // stack 문제
    // 그리디 문제인듯? top 이 동일하다면 pop -> 아니라면 push

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    vector<int> arr(N, 0);

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    int number = 1;
    int idx = 0;

    stack<int> st;

    vector<string> answer;
    while (number <= N)
    {
        if (!st.empty() && st.top() == arr[idx])
        {
            answer.push_back("-");
            idx++;
            st.pop();
        }
        else
        {
            answer.push_back("+");
            st.push(number);
            number++;
        }
    }

    while (!st.empty() && st.top() == arr[idx])
    {
        answer.push_back("-");
        idx++;
        st.pop();
    }

    if (idx != N)
    {
        cout << "NO\n";
    }
    else
    {
        for (string s : answer)
            cout << s << "\n";
    }

    return 0;
}