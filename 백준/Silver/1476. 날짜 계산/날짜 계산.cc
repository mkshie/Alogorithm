#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    int year = 1;
    int E, S, M;
    cin >> E >> S >> M;
    int o = 1, t = 1, th = 1;
    int max_o = 16, max_t = 29, max_th = 20;
    while(true){
        if(o == E && S ==t && th == M){
            break;
        }
        o = (o + 1) % max_o;
        if(o == 0) {
            o = 1;
        }
        t = (t + 1) % max_t;
        th = (th + 1) % max_th;
        if (t == 0)
        {
            t = 1;
        }
        if (th == 0)
        {
            th = 1;
        }
        year++;
    }
    cout << year << "\n";
}