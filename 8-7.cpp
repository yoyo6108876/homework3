#include<iostream>
using namespace std;
class PrimeNumber
{
public:
	PrimeNumber():prime(1){}
	PrimeNumber(int primenum):prime(primenum){}
	int getprime() { return prime; }
	PrimeNumber operator ++(int);
	PrimeNumber operator --(int);
	PrimeNumber operator ++();
	PrimeNumber operator --();
private:
	int prime;
};
int test(int num)
{
	bool a;
	do
	{
		a = true;
		for (int i = 2; i < num / 2; i++)
		{
			if (num % i == 0)
			{
				a = false;
				cout << "The is not prime. Please enter again." << endl;
				cin >> num;
			}
		}
	} while (!a);
	return num;
}
int
main()
{
	int num;
	cout << "Enter the prime number >> " << endl;
	cin >> num;
	num=test(num);
	PrimeNumber prime(num);
	prime++;
	prime--;
	PrimeNumber b=++prime;
	PrimeNumber c=--prime;
	cout << prime++.getprime() << endl;
	cout << prime--.getprime() << endl;
	cout << b.getprime() << endl;
	cout << c.getprime() << endl;
	

}
PrimeNumber PrimeNumber::operator ++(int prime2)
{
	int nextprime= prime;
	bool a = true;
	do
	{
		nextprime++;
		a = true;
		for (int i = 2; i < nextprime/2; i++)
		{
			if (nextprime % i == 0)
			{
				a = false;
			}
		}
	} while (!a);
	return PrimeNumber(nextprime);
}
PrimeNumber PrimeNumber::operator --(int prime2)
{
	int nextprime = prime;
	bool a = true;
	do
	{
		nextprime--;
		a = true;
		for (int i = 2; i < nextprime / 2; i++)
		{
			if (nextprime % i == 0)
			{
				a = false;
			}
		}
	} while (!a);

	return PrimeNumber(nextprime);
}
PrimeNumber PrimeNumber::operator ++()
{
	int nextprime = prime;
	bool a = true;
	do
	{
		++nextprime;
		a = true;
		for (int i = 2; i < nextprime / 2; i++)
		{
			if (nextprime % i == 0)
			{
				a = false;
			}
		}
	} while (!a);
	return PrimeNumber(nextprime);
}
PrimeNumber PrimeNumber::operator --()
{
	int nextprime = prime;
	bool a = true;
	do
	{
		--nextprime;
		a = true;
		for (int i = 2; i < nextprime / 2; i++)
		{
			if (nextprime % i == 0)
			{
				a = false;
			}
		}
	} while (!a);

	return PrimeNumber(nextprime);
}
