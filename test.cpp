#include"Fraction.h"
void test();
int main()
{
	test();
}
void test()
{
	Fraction f1(3,4), f2(1,2),f3(2,8),f4(4,1);
	f3 = f1 + f2;
	f3.show();
	f3 = f1 - f2;
	f3.show();
	f3 = f1 * f2;
	f3.show();
	f3 = f1 / f2;
	f3.show();
	f4.show();
}