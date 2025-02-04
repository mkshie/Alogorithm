#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
vector<int> answer;
vector<int> arr;

void rec_rotto(int start,int size,int cnt){
    if(size==6){
        for (int i = 0; i < 6;i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = start; i < arr.size();i++){
        if(answer.size()!=0 && answer.back() > arr[i])
            return;
        answer.push_back(arr[i]);
        rec_rotto(i + 1, size + 1,cnt);
        answer.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt;
    do{
        cin >> cnt;
        arr = vector<int>(cnt, 0);
        // vector<bool> che(cnt, false);
        for (int i = 0; i < cnt; i++)
        {
            cin >> arr[i];
        }
        rec_rotto(0, 0,cnt);
        cout << "\n";
    } while (cnt != 0);
    return 0;
}