#include <iostream>
#include <algorithm>

using namespace std;

int answer = 0;

int check_triangle(int num, int max_side)
{ // 두개를 합친
    int sum = 0;
    int one = num - 1;
    int two = 1;

    while (one >= two)
    {
        if (one <= max_side)
        {
            sum++;
        }

        one--;
        two++;
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 삼각형의 조건을 생각해야함
    // a <= b <= c 라고 하면 a + b > c 가 되어야 삼각형 조건이 성립
    // 최대 50,000 을 생각해보면
    // 5 일경우  113 , 122  , 131 , 221 , 3 1 1
    // 즉 숫자 두개만 만들어두고 판별해나가면 됨 max 변수 값 기록해두고

    int num;
    cin >> num;

    if (num == 3)
    {
        cout << 1 << "\n";
        return 0;
    }

    int A = num - 2; // 남은 두변의 합
    int B = 2;       // 삼각형중 제일 긴 변

    while (A > B)
    { // 두변의 합이 제일 긴 변의 길이보다 커야 삼각형이 될 수 있음

        if (A - B <= B)
        { // 두변의 합에서 제일 긴 변의 길이를 뺏을때 남은 변의 길이가 제일 긴 변의 길이보다 작거나 같아야함
            answer += check_triangle(A, B);
        }

        A--;
        B++;
    }

    cout << answer << "\n";

    return 0;
}