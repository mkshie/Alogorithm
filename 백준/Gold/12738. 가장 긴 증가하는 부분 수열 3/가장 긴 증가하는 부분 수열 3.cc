#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long int> arr;
    vector<long int> lis;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long int num;
        cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < n;i++){
        long int num = arr[i];
        auto it = lower_bound(lis.begin(), lis.end(), num);

        if(it == lis.end()){
            lis.push_back(num);
        }
        else{
            *it = num;
        }
    }
    cout << lis.size() << "\n";

    return 0;
}