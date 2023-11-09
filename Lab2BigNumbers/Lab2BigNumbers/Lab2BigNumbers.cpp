#include <iostream>
#include "ConstHeader.h"


using namespace std;

int main()
{
	CNumber num1("999999");
	CNumber num2("9999");
	CNumber *num3 = new CNumber(num1);
	CNumber num4("-999999");
	CNumber num5("-999");
	CNumber num6("-4324");
	CNumber num7("-32323333333232");
	CNumber num8;
	CNumber num9("-900000");
	CNumber num10("0");
	CNumber num11("2");

	CNumber res1;
	CNumber res2;
	CNumber res3;
	CNumber res4;
	CNumber res5;
	CNumber res6;
	CNumber res7;
	CNumber res8;
	CNumber res9;
	CNumber res10;
	CNumber res11;
	CNumber res12;
	CNumber res13;
	CNumber res14;
	CNumber res15;
	CNumber res16;
	CNumber res17;
	CNumber res18;
	CNumber res19;
	CNumber res20;
	CNumber res21;

	cout << num1.toStr() << endl;
	cout << num2.toStr() << endl;
	cout << num3->toStr() << endl;
	cout << "\n" << endl;

	num8 = num1;
	cout << num8.toStr() << endl;
	cout << num1.toStr() << endl;
	cout << &num4 << endl;
	cout << &num1 << endl;
	cout << "\n" << endl;

	res1 = num1 + num2;
	res2 = num1 + num5;
	res3 = num4 + num2;
	res4 = num4 + num5;
	res5 = num1 + num9;
	cout << res1.toStr() << endl;
	cout << res2.toStr() << endl;
	cout << res3.toStr() << endl;
	cout << res4.toStr() << endl;
	cout << res5.toStr() << endl;
	cout << "\n" << endl;

	res6 = num1 - num2;
	res7 = num5 - num1;
	res8 = num4 - num2;
	res9 = num1 - num4;
	res10 = num1 - num1;
	cout << res6.toStr() << endl;
	cout << res7.toStr() << endl;
	cout << res8.toStr() << endl;
	cout << res9.toStr() << endl;
	cout << res10.toStr() << endl;
	cout << "\n" << endl;

	res11 = num1 * num2;
	res12 = num1 * num4;
	res13 = num4 * num2;
	res14 = num4 * num5;
	res15 = num1 * num10;
	cout << res11.toStr() << endl;
	cout << res12.toStr() << endl;
	cout << res13.toStr() << endl;
	cout << res14.toStr() << endl;
	cout << res15.toStr() << endl;
	cout << "\n" << endl;

	res16 = num1 / num2;
	res17 = num1 / num4;
	res18 = num4 / num2;
	res19 = num4 / num5;
	res20 = num1 / num11;
	res21 = num1 / num10;

	cout << res16.toStr() << endl;
	cout << res17.toStr() << endl;
	cout << res18.toStr() << endl;
	cout << res19.toStr() << endl;
	cout << res20.toStr() << endl;
	cout << res21.toStr() << endl;

	CNumber pow;
	CNumber exp("2");
	pow = pow.CNumPower(exp, 8);
	cout << pow.toStr() << endl;


	return 0;
}