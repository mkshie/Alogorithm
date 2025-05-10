#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int A, B, C;
    cin >> A >> B >> C;
    int num = B;
    long long int answer = 1;
    A = A % C;
    while(B > 0){
        if(B % 2 == 1){
            answer = (answer * A) % C;
        }
        A = (A * A) % C;
        B = B / 2;
    }
    cout << answer << "\n";
}