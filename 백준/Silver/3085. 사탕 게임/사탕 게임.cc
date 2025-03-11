#include <iostream>
#include <algorithm>

using namespace std;

//이런 값이 작은 문제는 그냥 전부 다 바꿔보면서 돌아도 시간이 충분하다는걸 알려주는 문제
//처음에는 어떻게 효율적으로 계산해야하나 고민했지만 매우 간단하게 풀린다

char arr[51][51];
int N;
int max_cnt = 0, answer; // 최대값 , 정답 변수

void row_check(){
    int ch_num = 0;
    for (int dy = 0; dy < N; dy++){
        int count = 1;
        for (int dx = 0; dx < N; dx++)
        {
           if(arr[dy][dx] == arr[dy][dx+1]){ // 다음 문자가 같으면 길이 증가
               count++;
           }
           else{
            if(max_cnt < count)
                max_cnt = count;
            count = 1;
           }
           
        }
    }
}
void column_check(){
    int ch_num = 0;
    for (int dx = 0; dx < N; dx++)
    {
        int count = 1;
        for (int dy = 0; dy < N; dy++)
        {
            if (arr[dy][dx] == arr[dy+1][dx])
            { // 다음 문자가 같으면 길이 증가
                count++;
            }
            else
            {
                if (max_cnt < count)
                    max_cnt = count;
                count = 1;
            }
            
        }
    }
}
int main(){

    cin.tie(NULL);

    cin >> N;
   
    char color;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N;j++){
            cin >> color;
            arr[i][j] = color;
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-1; j++){
            swap(arr[i][j], arr[i][j + 1]); // 가로 부분 swap
            row_check();
            column_check();

            swap(arr[i][j], arr[i][j + 1]); // 원래대로 복구

            swap(arr[i][j], arr[i + 1][j]); // 세로 부분 swap

            row_check();
            column_check();

            swap(arr[i][j], arr[i + 1][j]);
        }
    }
    cout << max_cnt << "\n";
}
