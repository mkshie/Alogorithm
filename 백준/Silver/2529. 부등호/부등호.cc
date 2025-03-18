#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string answer_max = "000000";
string answer_min = "999999";
string cur_string = "";

int arr[10] = {0};
vector<char> big_small;

int k;

void back_tracking(int size){
    if(size == k+1){
        answer_max = max(answer_max, cur_string);
        answer_min = min(answer_min, cur_string);
        return;
    }
    for (int i = 0; i < 10;i++){
        if (arr[i] == 0)
        {
            if (size == 0)
            {
                cur_string += to_string(i);
                arr[i]++;
                back_tracking(size + 1);
                arr[i]--;
                cur_string = "";
            }
            else{
                int num = cur_string[size - 1] - '0';
                if (big_small[size - 1] == '<' && cur_string[size - 1] - '0' < i)
                {
                    cur_string += to_string(i);
                    arr[i]++;
                    back_tracking(size + 1);
                    arr[i]--;
                    cur_string.erase(size, 1);
                }
                else if (big_small[size - 1] == '>' && cur_string[size - 1] - '0' > i)
                {
                    cur_string += to_string(i);
                    arr[i]++;
                    back_tracking(size + 1);
                    arr[i]--;
                    cur_string.erase(size, 1);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    big_small = vector<char> (k,' ');
    for (int i = 0; i < k; i++)
    {
        cin >> big_small[i];
    }
    back_tracking(0);
    cout << answer_max << "\n"
         << answer_min << "\n";

    return 0;
}