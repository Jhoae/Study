#include <iostream>


int add(int x, int y)
{
	return x + y;
}
auto Dadd(int x, int y)
{
	return x + (double)y;
}
auto subtract(int x, int y)
{
	return x - y;
}

// auto AutoAdd(auto x, auto y) { return a + b }; 
// parameter(�Ű�����) type���� auto Ű���� ��� �Ұ���
// ��� template �� ��밡��


// ���븦 ����� - �ڵ� ������ 
auto Tadd(int x, int y) -> int
{
	return x + y;
}


int main()
{
	using namespace std;

	auto a = 123;	// �ڷ����� �߷��Ͽ� ������ ���ϰ� �����.
	// auto b;		// �ʱ�ȭ�� ���������� auto Ű���� ���Ұ�
	auto b = 123.0;
	auto c = 1 + 2.0;

	auto result = add(1, 2);		// �Լ� int  , ��� int
	auto result = Dadd(1, 2);		// �Լ� auto , ��� double
	auto result2 = subtract(3, 2);	// �Լ� auto , ��� int

	return 0;
}