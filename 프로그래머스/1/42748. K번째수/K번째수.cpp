#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> copy_array = array;
    for(int p=0;p<commands.size();p++){
        array = copy_array;
        int i = commands[p][0];
        int j = commands[p][1];
        int k = commands[p][2];
        vector<int> arr;
        for(int pp = i-1 ; pp < j ; pp++){
            arr.push_back(array[pp]);
        }
        sort(arr.begin(),arr.end());
        answer.push_back(arr[k-1]);
    }
    return answer;
}