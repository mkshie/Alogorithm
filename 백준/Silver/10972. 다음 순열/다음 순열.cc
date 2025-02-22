#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> arr;
    for(int i=0;i<N;i++){
        int y;
        cin >> y;
        arr.push_back(y);
    }
    if(next_permutation(arr.begin(),arr.end())){
        for(int i=0;i < arr.size();i++)
            cout<< arr[i] << " ";
    }
    else
        cout<< -1;
    
    return 0;
}