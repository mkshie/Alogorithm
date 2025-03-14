#include <iostream>

using namespace std;

//에라토스테네스의 체를 이용하여 미리 소수 판정 후
//복잡도를 내리기 위해서 n 의 절반까지만 확인하기

bool arr[1000001] = {false};

void check_odd(){
    for (int i = 2; i < 500000;i++){
        for (int j = 2; i * j < 1000001;j++){
            arr[i * j] = true; // 소수를 에라토스테네스의 체로 미리 판정
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string wrong_answer = "Glodbach's conjecture is wrong.";
    int n;
    check_odd();
    while (cin >> n)
    {
        bool check_bool = false;
        if (n == 0)
            break;
        for (int i = 3; i <= n / 2; i++)
        {
            if(arr[i]){ // 소수가 아니라면 패스
                continue;
            }
            else if(!arr[i] && !arr[n-i]){ // i 가 소수면서 n - i 역시 소수라면 두 소수로 나타낼 수 있음
                cout << n << " = " << i << " + " << n - i << "\n";
                check_bool = true;
                break;
            }
        }
        if(!check_bool){
            cout << wrong_answer << "\n";
        }
    }
    return 0;
}