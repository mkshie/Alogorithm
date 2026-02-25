#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

int che_op(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string prob;
    cin >> prob;

    stack<char> st;
    string answer = "";

    for (char ch : prob)
    {
        if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        { // 연산자 처리 과정
            // stack 이 비워져 있거나 연산자 우선순위가 나보다 낮으면 삽입
            if (st.empty() || st.top() == '(' || che_op(st.top()) < che_op(ch))
            {
                st.push(ch);
            }
            else
            {
                while (!st.empty() && che_op(st.top()) >= che_op(ch))
                {
                    answer += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            //( 만날때까지 pop 해주기
            while (st.top() != '(')
            {
                answer += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            answer += ch;
        }
    }
    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }

    cout << answer << "\n";
    return 0;
}