#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
	using namespace std;

	float f(3.141592f);				
	double d(3.141592);				
	long double ld(3.141592);		

	cout << sizeof(float) << endl;	// 4
	cout << sizeof(d) << endl;		// 8
	cout << sizeof(ld) << endl;		// 8


	cout << numeric_limits<float>::max() << endl;				// 3.40282e+38
	cout << numeric_limits<double>::max() << endl;				// 1.79769e+308
	cout << numeric_limits<long double>::max() << endl;			// 1.79769e+308
	printf("\n");
	
	cout << numeric_limits<float>::min() << endl;				// 1.17549e-38
	cout << numeric_limits<double>::min() << endl;				// 2.22507e-308
	cout << numeric_limits<long double>::min() << endl;			// 2.22507e-308
	printf("\n");
	
	cout << numeric_limits<float>::lowest() << endl;			// -3.40282e+38
	cout << numeric_limits<double>::lowest() << endl;			// -1.79769e+308
	cout << numeric_limits<long double>::lowest() << endl;		// -1.79769e+308
	printf("\n");


	cout << 3.14 << endl;		// 3.14
	cout << 31.4e-1 << endl;	// 3.14
	cout << 31.4e-2 << endl;	// 0.314
	cout << 31.4e1 << endl;		// 314
	cout << 31.4e2 << endl;		// 3140
	printf("\n");


	
	cout << std::setprecision(16);
	cout << 1.0 / 3.0 << endl;	// 0.3333333333333333

	float fl(123456789.0f); // 10 significant digits
	cout << std::setprecision(9);
	cout << fl << endl;		// 123456792 :: 정밀도가 떨어진다.
	printf("\n");

	double dl(0.1);
	cout << dl << endl;				// 0.1
	cout << std::setprecision(17);
	cout << dl << endl;				// 0.10000000000000001
	printf("\n");


	double d1(1.0);
	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

	cout << d1 << endl;	// 1
	cout << d2 << endl;	// 0.99999999999999989
	printf("\n");


	double zero = 0.0;
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;

	cout << posinf << " " << std::isinf(posinf) << endl;	// inf 1
	cout << neginf << " " << std::isinf(neginf) << endl;	// -inf 1
	cout << nan << " " << std::isnan(nan) << endl;			// -nan(ind) 1
	cout << 1.0 << " " << std::isnan(1.0) << endl;			// -nan(ind) 0
	printf("\n");

	return 0;
}