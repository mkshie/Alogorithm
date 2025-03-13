#include <iostream>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        int ans = 1;
        int k = 1;
        while (true)
        {
            if(ans % n == 0){
                break;
            }
            else{
                k++;
                ans = ans * 10 + 1;
                ans %= n;
            }
        }
        cout << k << "\n";
    }
}