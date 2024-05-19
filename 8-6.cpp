#include<iostream>
#include<math.h>
using namespace std;
class MyInteger
{
public:
	MyInteger() :integer(0) {}
	int getinteger() { return integer; }
	void SetInteger(int integer) { this->integer = integer; }
	int operator[](int index);
private:
	int integer;
};
int
main()
{
	MyInteger integer;
	int num, index = 0;
	cin >> num;
	integer.SetInteger(num);
	while (num != 0)
	{
		num /= 10;
		index++;
	}
	cout << "The integer is " << integer.getinteger() << endl;
	for (int i = 0; i < index + 1; i++)
	{
		cout << "x[" << i << "] is " << integer[i] << " ";
	}
}
int MyInteger::operator[](int index)
{
	int size = 0;
	int replace = integer;
	while (replace != 0)
	{
		replace /= 10;
		size++;
	}
	int target;
	target = integer;
	int a = pow(10, index + 1);
	int remainder = target % a;
	int b = pow(10, index);
	remainder = remainder / b;
	return remainder;
}