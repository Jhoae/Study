#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
	using namespace std;

	// 가명 (별명)
	typedef double  distance_t; // 주로 뒤에 _t를 붙임
    // ex
	std::int8_t i(97);


	// 컴파일러 입장에서는 똑같다. 
	// 다만 프로그래밍 편의를 위해 사용한다.
	// 보기도 좋고, 유지/관리(수정)하기도 편하고
	double my_distance;
	distance_t home2work;
	distance_t home2school;


	/*	 복잡한 자료형 예시를 간단히	*/
	vector<pair<string, int> >pairlist1;
	vector<pair<string, int> >pairlist2;

	// ->
	typedef vector<pair<string, int> > pairlist_t;
	pairlist_t pairlist3;
	pairlist_t pairlist4;


	/* using을 사용하는 경우도 가능			*/
	// "="를 사용하긴 해도"할당하는것이 아니라", 컴파일러에 알려주는것.
	using pairlist_t = vector<pair<string, int> >;


	return 0;
}