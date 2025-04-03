#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<int> arr[H + X];
    for (int i = 0; i < H + X;i++){
        for (int j = 0; j < W + Y; j++){
            int num;
            cin >> num;
            arr[i].push_back(num);
        }
    }
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            arr[i + X][j + Y] -= arr[i][j];
        }
    }
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}