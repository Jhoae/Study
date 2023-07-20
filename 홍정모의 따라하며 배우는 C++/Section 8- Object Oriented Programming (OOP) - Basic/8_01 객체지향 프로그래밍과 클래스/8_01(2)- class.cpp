// ��ü���� object�� �� �� �ٷ�� ���� class

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* �Ϲ������� �Լ��� �������� struct ��� class�� ��� 
   - ��ü(Object)��°� �����Ϳ� print����� ��� ���������� �����ϴ� ��.
   - ��ü��� ������ ���α׷� ���μ� �����ϴ� Ű���尡 class�̴�. */

class Friend_class 
{
public: // ���� ������: acess specifier  (public, private, protected)
	string m_name; // m_ : member
	string m_address;
	int m_age;
	double m_height;
	double m_weight;

	void printFriend()
	{
		cout << "class.name: " << m_name << endl;
		cout << "class.address: " << m_address << endl;
		cout << "class.age: " << m_age << endl;
		cout << "class.height: " << m_height << endl;
		cout << "class.weight: " << m_weight << endl;
	}
};




int main()
{
	// ������ �޸𸮸� �����ϵ��� �����ϴ� �� : instanciation
	Friend_class kk{ "Jack Jack" ,"Uptown" , 26, 173.2, 65.5 };

	// kk�� Friend_class�� instance�̴�.
	kk.printFriend();
	cout << "&kk" << &kk << endl;

/* Ÿ������ �������� ª�� �����ϰ� �ٲٱ� */
	vector<Friend_class> my_friends;
	my_friends.resize(2);

	// my_friends[0].printFriend();
	// my_friends[1].printFriend();
	for (auto& e : my_friends)
		e.printFriend();

	return 0;
}