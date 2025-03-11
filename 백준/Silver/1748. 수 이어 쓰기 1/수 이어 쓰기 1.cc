#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt = 0;
    int y = 1;
    int x = 9;
    while(true){
        if(N < x){
            cnt += y * N;
            break;
        }
        cnt += y * x;
        N = N - x;
        x = x * 10;
        y++;
    }
    cout << cnt << "\n";
    return 0;
}