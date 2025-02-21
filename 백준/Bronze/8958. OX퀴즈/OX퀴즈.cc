#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a = 0;
	string str1 = "";
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		cin >> str1;
		int sum = 0;
		int s = str1.size();
		int check = 1;
		for (int b = 0; b < s; b++)
		{
			if (str1[b] == 'O')
			{
				if (check != 1)
				{
					sum += check;
					check++;
				}
				else
				{
					sum += 1;
					check++;
				}
			}
			else
			{
				check = 1;
				/*sum += 1*/
			}
		}

		cout << sum << endl;
	}

	return 0;

}
























//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//
//}

