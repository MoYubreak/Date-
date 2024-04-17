#include"Date.h"

void TestDate1()
{
	Date d1(2024, 4, 17);
	Date d2(2059, 12, 21);

	/*cout << d1-d2;*/
	cin >> d1;
	cout << d1;
}

int main()
{
	TestDate1();
	return 0;
}