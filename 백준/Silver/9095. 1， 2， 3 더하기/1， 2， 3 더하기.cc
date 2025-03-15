#include <iostream>

using namespace std;

int answer = 0;

void check(int n){
    for (int i = 1; i < 4;i++){
        if(n - i > 0){
            check(n - i);
        }
        else if(n - i == 0){
            answer++;
            return;
        }
        else{
            return;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        answer = 0;
        check(n);
        cout << answer << "\n";
    }
}