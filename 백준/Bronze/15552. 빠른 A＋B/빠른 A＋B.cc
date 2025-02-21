#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int t,a,b;
    cin >> t;
    if(!(t >= 1 && t <= 1000000))
    {
        return 0;
    }
    for(int i = 0; i < t; i++)
    {
        cin >> a;
        cin >> b;
        if(!(a >= 1 && a <= 1000))
        {
            return 0;
        }
        if(!(b >= 1 && b <= 1000))
        {
            return 0;
        }
        cout << a+b << "\n";
    }
    return 0;
}
