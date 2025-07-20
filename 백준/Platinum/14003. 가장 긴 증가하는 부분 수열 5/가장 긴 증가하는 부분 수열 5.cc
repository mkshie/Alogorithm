#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long int> arr;
    vector<long int> lis;
    vector<vector<pair<int, int>>> lis_idx;
    // vector<int> lis_cnt;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long int num;
        cin >> num;
        arr.push_back(num);
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        long int num = arr[i];
        auto it = lower_bound(lis.begin(), lis.end(), num);
        int idx = it - lis.begin(); // 해당 값의 idx 값.

        if (it == lis.end())
        {
            lis.push_back(num);
            lis_idx.push_back(vector<pair<int,int>>());
            lis_idx[idx].push_back({i, num});
        }
        else
        {
            *it = num;
            // cnt++;
            lis_idx[idx].push_back({i, num});
        }
    }
    cout << lis.size() << "\n";
    for (int i = lis.size() - 1; i >= 1; i--) // 역추적으로 생각을 바꾸자
    {
        int cur_idx = lis_idx[i].back().first;
        int cur_num = lis_idx[i].back().second;

        int pre_idx = lis_idx[i - 1].back().first;
        int pre_num = lis_idx[i - 1].back().second;

        if (cur_idx < pre_idx)
        {
            lis_idx[i - 1].pop_back();
            while (true)
            {
                pre_idx = lis_idx[i -1].back().first;
                pre_num = lis_idx[i - 1].back().second;
                if(cur_idx > pre_idx && cur_num > pre_num){
                    lis[i-1] = pre_num;
                    break;
                }
                lis_idx[i-1].pop_back();
            }
        }
    }
    for (long int num : lis)
        cout << num << " ";
    cout << "\n";
    return 0;
}