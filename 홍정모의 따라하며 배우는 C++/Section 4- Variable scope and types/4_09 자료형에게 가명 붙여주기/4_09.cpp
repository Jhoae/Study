#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
	using namespace std;

	// ���� (����)
	typedef double  distance_t; // �ַ� �ڿ� _t�� ����
    // ex
	std::int8_t i(97);


	// �����Ϸ� ���忡���� �Ȱ���. 
	// �ٸ� ���α׷��� ���Ǹ� ���� ����Ѵ�.
	// ���⵵ ����, ����/����(����)�ϱ⵵ ���ϰ�
	double my_distance;
	distance_t home2work;
	distance_t home2school;


	/*	 ������ �ڷ��� ���ø� ������	*/
	vector<pair<string, int> >pairlist1;
	vector<pair<string, int> >pairlist2;

	// ->
	typedef vector<pair<string, int> > pairlist_t;
	pairlist_t pairlist3;
	pairlist_t pairlist4;


	/* using�� ����ϴ� ��쵵 ����			*/
	// "="�� ����ϱ� �ص�"�Ҵ��ϴ°��� �ƴ϶�", �����Ϸ��� �˷��ִ°�.
	using pairlist_t = vector<pair<string, int> >;


	return 0;
}