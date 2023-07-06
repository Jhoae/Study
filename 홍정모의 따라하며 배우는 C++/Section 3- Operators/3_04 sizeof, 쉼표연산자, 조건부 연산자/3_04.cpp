#include <iostream>

int getPrice(bool onSale)
{
	if (onSale)
		return 10;
	else
		return 100;
}

int main()
{
	using namespace std;

	float fl;

	sizeof(float);		// 4 (bytes)
	sizeof(fl);			// 4 (bytes)



	/*			comma 연산자				 */
	
	/* 아래와 같다
		++x;
		++y;
		int z = y;
	*/
	int x = 3;
	int y = 10;
	int z = (++x, ++y);
	
	cout << x << " " << y << " " << z << endl;	// 4 11 11
	


	/*		comma 연산자 활용				 */
	int a = 1;
	int b = 10;
	int c;
	c = a, b;	
	cout << c << endl;  // 1 -----이유---->  ( c = a ), b  로 처리됨
	
	c = (a, b);
	cout << c << endl;	// 10

	c = (++a, a + b);
	cout << c << endl;	// 12

	


	/*		조건부 연산자	(삼항 연산자)		conditional operator				*/
	int p;
	bool onSale = true;


	const int price = (onSale == true) ? 10 : 100; // const를 활용하고 싶을 경우 
	// const int price = getPrice(onSale);		// 함수를 활용하여 정의하면 -> 비추
	
	/* if문으로 사용하면 위와 같다 ( const는 X )
		int price;
	
		if (onSale)
			price = 10;
		else price = 100;
	*/


	cout << price << endl;





	/*	같은 타입(숫자, 문자 등)을 출력하는 것을 추천		*/
	int g = 5;
	cout << ((g % 2 == 0) ? "even" : "odd") << endl;

	return 0;
}