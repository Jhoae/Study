// 객체지향 object를 더 잘 다루기 위한 class

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 일반적으로 함수를 넣을때는 struct 대신 class를 사용 
   - 객체(Object)라는건 데이터와 print기능을 묶어서 개념적으로 생각하는 것.
   - 객체라는 개념을 프로그램 언어로서 구현하는 키워드가 class이다. */

class Friend_class 
{
public: // 접근 지정자: acess specifier  (public, private, protected)
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
	// 실제로 메모리를 차지하도록 정의하는 것 : instanciation
	Friend_class kk{ "Jack Jack" ,"Uptown" , 26, 173.2, 65.5 };

	// kk는 Friend_class의 instance이다.
	kk.printFriend();
	cout << "&kk" << &kk << endl;

/* 타이핑이 많아질때 짧고 간결하게 바꾸기 */
	vector<Friend_class> my_friends;
	my_friends.resize(2);

	// my_friends[0].printFriend();
	// my_friends[1].printFriend();
	for (auto& e : my_friends)
		e.printFriend();

	return 0;
}