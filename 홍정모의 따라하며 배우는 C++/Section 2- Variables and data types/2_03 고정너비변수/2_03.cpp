// C++ 11~ 사용가능
// 멀티 플랫폼에서 주로 사용

#include <iostream>
#include <cstdint>

int main()
{
	using namespace std;

	std::int16_t i(5);			// 16비트 = 2바이트  
	std::int8_t myint = 65;		//  8비트 = 1바이트 : typedef signed char
	
	cout << myint << endl;		// 'A'

	std::int_fast8_t fi(5);		// 적어도 8비트를 갖는 데이터 타입중 사이즈중 가장 빠른것 : typedef signed char
	std::int_least64_t fl(5);	// 적어도 64비트를 갖는 데이터 타입중 사이즈중 가장 빠른것 : typedef long long



	return 0;
}