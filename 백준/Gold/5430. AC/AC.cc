#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <sstream>

using namespace std;
int T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string order;
        cin >> order;
        int arr_size;
        cin >> arr_size;

        deque<int> arr;

        string arr_string;
        cin >> arr_string;

        arr_string.erase(arr_string.begin());
        arr_string.pop_back();

        string token;
        stringstream arr_str(arr_string);

        while (getline(arr_str, token, ','))
        {
            if (!token.empty())
                arr.push_back(stoi(token));
        }

        int dir = 0;
        bool che = true;

        for (char ch : order)
        {
            // 비어있는데 버리면 error 발생
            if (ch == 'R')
            {
                dir = (dir == 0) ? 1 : 0;
            }
            else
            {

                if (arr.size() == 0)
                {
                    cout << "error\n";
                    che = false;
                    break;
                }

                dir == 0 ? arr.pop_front() : arr.pop_back();
            }
        }

        if (!che)
            continue;

        cout << "[";
        while (!arr.empty())
        {
            cout << ((dir == 0) ? arr.front() : arr.back());

            dir == 0 ? arr.pop_front() : arr.pop_back();

            if (arr.size() != 0)
            {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}