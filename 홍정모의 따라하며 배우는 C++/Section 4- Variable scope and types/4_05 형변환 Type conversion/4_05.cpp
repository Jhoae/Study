#include <iostream>
#include <typeinfo>
#include <iomanip>


int main()
{
	using namespace std;

	int a = 123;
	cout << typeid(4.0).name() << endl;	// 어떤 data type인지 출력해줌
	cout << typeid(a).name() << endl;	




	printf("\n");
	/* 	numeric conversion - 더 넓은곳으로 할당	*/
	float b = 1.0f;
	double c = a;	// numeric promotion :: f < d ==> 더 넓은 곳에 할당 -> 문제X



	/*	numeric conversion - 더 좁은곳으로 할당	*/		
	int i = 30000;
	char d = i; // char은 30000을 담을수 없음.
	cout << static_cast<int>(d) << endl;	// 더 좁은곳에 할당되므로 제대로 저장X


	double e = 0.123456789;
	float f = e;
	cout << std::setprecision(12) << f << endl;	// 더 좁은곳에 할당되므로 제대로 저장X

	float g = 3.14;
	int h = g;
	cout << std::setprecision(12) << h << endl;	// 더 좁은곳에 할당되므로 제대로 저장X


	cout << 5u - 10u << endl; // u: unsigned // 에러의 이유 == 형변환 우선순위
	
	// 형변환 우선순위 (오름차순)
	// int, unsigned int, long, unsigned long,
	// long long, unsigned long long, float, double
	// long double


	/*	명시적 casting	*/
	int k = int(4.0);
	int l = (int)4.0;
	int m = static_cast<int>(4.0);

	return 0;
}