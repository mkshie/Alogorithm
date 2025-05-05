#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str1;
    cin >> str1;
    size_t pos = str1.find('-');
    int left = 0 , right = 0;
    string str2 = "";
    for (int i = 0; i < str1.size(); i++)
    {
        if(i + 1 == str1.size()){
            str2 += str1[i];
            if(pos == string::npos) // 음수가 없었음
            {
                left += stoi(str2);
            }
            else{
                right += stoi(str2);
            }
        }
        if(pos == string::npos || i <= pos){ // - 가 존재하지 않는다면?
            if(str1[i] != '+' && str1[i] != '-') // 부호가 아니라면
            {
                str2 += str1[i];
            }
            else{
                left += stoi(str2);
                str2 = "";
                continue;
            }
        }
        else{
            if (str1[i] != '+' && str1[i] != '-') // 부호가 아니라면
            {
                str2 += str1[i];
            }
            else
            {
                right += stoi(str2);
                str2 = "";
                continue;
            }
        }
    }
    cout << left - right << "\n";
    return 0;
}