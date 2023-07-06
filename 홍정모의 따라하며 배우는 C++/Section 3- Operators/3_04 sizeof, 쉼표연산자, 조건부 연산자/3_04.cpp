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



	/*			comma ������				 */
	
	/* �Ʒ��� ����
		++x;
		++y;
		int z = y;
	*/
	int x = 3;
	int y = 10;
	int z = (++x, ++y);
	
	cout << x << " " << y << " " << z << endl;	// 4 11 11
	


	/*		comma ������ Ȱ��				 */
	int a = 1;
	int b = 10;
	int c;
	c = a, b;	
	cout << c << endl;  // 1 -----����---->  ( c = a ), b  �� ó����
	
	c = (a, b);
	cout << c << endl;	// 10

	c = (++a, a + b);
	cout << c << endl;	// 12

	


	/*		���Ǻ� ������	(���� ������)		conditional operator				*/
	int p;
	bool onSale = true;


	const int price = (onSale == true) ? 10 : 100; // const�� Ȱ���ϰ� ���� ��� 
	// const int price = getPrice(onSale);		// �Լ��� Ȱ���Ͽ� �����ϸ� -> ����
	
	/* if������ ����ϸ� ���� ���� ( const�� X )
		int price;
	
		if (onSale)
			price = 10;
		else price = 100;
	*/


	cout << price << endl;





	/*	���� Ÿ��(����, ���� ��)�� ����ϴ� ���� ��õ		*/
	int g = 5;
	cout << ((g % 2 == 0) ? "even" : "odd") << endl;

	return 0;
}