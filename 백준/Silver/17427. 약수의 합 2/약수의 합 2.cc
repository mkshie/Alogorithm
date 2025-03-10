#include <iostream>

using namespace std;
//숫자 x 가 N 이하에 약수가 몇번 들어가는지 알아내는 문제 
//숫자 1 은 10 이하에 10 번 숫자 2는 5번 숫자 3은 3번... 10 / x 의 개수만큼 들어감
int main(){
    int N;
    cin >> N;
    long long int sum = 0;

    for (int i = 1; i < N; i++){
        sum += (N / i) * i;
    }
    sum += N;
    cout << sum << endl;
}