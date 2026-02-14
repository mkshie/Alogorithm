#include <string>
#include <iostream>

using namespace std;

int main()
{
    long long int A, B;

    cin >> A >> B;

    while (A)
    {
        long long int C = A;
        A = B % A;
        B = C;
    }

    string answer = "";

    for (int i = 0; i < B; i++)
    {
        answer += "1";
    }

    cout << answer << "\n";

    return 0;
}