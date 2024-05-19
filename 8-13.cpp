#include<iostream>
using namespace std;
class Complex
{
public:
	Complex(int realnum, int imangenum) :real(realnum), imangnary(imangenum) {}
	Complex() :real(0),imangnary(1){}
	const double getreal() { return real; }
	const double getimangary() { return imangnary; }
	const void realoutput() { cout << real; }
	const void imangoutput() { cout << " + " << imangnary << "i" << endl; }
	friend const Complex operator+ (Complex&, Complex&);
	friend const Complex operator- (Complex&, Complex&);
	friend const Complex operator* (Complex&, Complex&);
	friend bool operator== (Complex&, Complex&);
	friend ostream& operator <<(ostream& outputStream,const Complex& );
	friend istream& operator >>(istream& outputStream, const Complex&);

private:
	double real;
	double imangnary;
};
int 
main()
{
	int a = 1, b = 2, c = 3, d = 4;
	Complex set1(a, b), set2(c, d), total,diff,abc;
	total = set1 + set2;
	diff = set1 - set2;
	abc = set1 * set2;
	cout <<"set1: "<< set1;
	cout << "set2:"<<set2;
	cout << "total: " << total;
	cout << "diff: " << diff;
	cout << "abc: " << abc;

}
const Complex operator+ (Complex& set1, Complex& set2)
{
	double realnumtotal = set1.getreal() + set2.getreal();
	double imangnarytotal = set1.getimangary() + set2.getimangary();
	return Complex(realnumtotal, imangnarytotal);
}
const Complex operator- (Complex& set1, Complex& set2)
{
	double realnumtotal = set1.real - set2.getreal();
	double imangnarytotal = set1.getimangary() - set2.getimangary();
	return Complex(realnumtotal, imangnarytotal);
}
const Complex operator* (Complex& set1, Complex& set2)
{
	double realnumtotal = (set1.getreal() * set2.getreal())- (set1.getimangary() + set2.getimangary());
	double imangnarytotal = ((set1.getimangary() * set2.getreal())+ (set2.getimangary() * set1.getreal()));
	return Complex(realnumtotal, imangnarytotal);
}
bool operator== (Complex& set1, Complex& set2)
{
	return (set1.imangnary == set2.imangnary && set1.real == set2.real);
}
ostream& operator<< (ostream& outputStream, const Complex& set)
{
	outputStream << set.real << " + " << set.imangnary << "i" << endl;
	return outputStream;

}