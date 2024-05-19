#include<iostream>
#include<string.h>
using namespace std;
int
main()
{
	string a[10];
	int i = 0;
	bool b = true;
	do
	{
		cin >> a[i];
		if (a[i].size()==4)
		{
			if (isupper(a[i][0])&&(islower(a[i][3])))
			{
				a[i] = { "Love" };
			}
			else if (islower(a[i][0])&&(islower(a[i][3])))
			{
				a[i] = { "love" };
			}
		}
		if (a[i].compare("....")==0)
		{
			b = false;
		}
		i++;
	} while (b== true);
	for (int j = 0; j < i-1; j++)
	{
		cout << a[j] << " ";
	}
}