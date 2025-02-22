#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int x1 = 0;
    int y1 = 0;
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0] < sizes[i][1]){ //큰값을 한쪽으로 몰아서 넣기
            x1 = max(x1,sizes[i][1]);
            y1 = max(y1,sizes[i][0]);
        }
        else{
            x1 = max(x1,sizes[i][0]);
            y1 = max(y1,sizes[i][1]);
        }
    } // 일단 현재의 최대 값 구하기
    return x1*y1;
}