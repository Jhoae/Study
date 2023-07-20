#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 객체지향 없이 기존 코드 */
// Friend : name, address, age, height, weight, ...
void printFriend(const string& name, const string& address, 
	const int& age, const double& height, const double& weight)
{
	cout << "name: " << name << endl;
	cout << "address: " << address << endl;
	cout << "age: " << age << endl;
	cout << "height: " << height << endl;
	cout << "weight: " << weight << endl;
}

/* 구조체를 이용할 경우 */

struct Friend
{
	string name;
	string address;
	int age;
	double height;
	double weight;
};

// 함수 오버로딩
void printFriend(const Friend &fr)
{
	cout << "fr.name: " << fr.name << endl;
	cout << "fr.address: " << fr.address << endl;
	cout << "fr.age: " << fr.age << endl;
	cout << "fr.height: " << fr.height << endl;
	cout << "fr.weight: " << fr.weight << endl;
}

/* struct 안에 함수 넣기 */
struct Friend_func
{
	string name;
	string address;
	int age;
	double height;
	double weight;

	void printFriend()
	{
		cout << "Friend_func.name: " << name << endl;
		cout << "Friend_func.address: " << address << endl;
		cout << "Friend_func.age: " << age << endl;
		cout << "Friend_func.height: " << height << endl;
		cout << "Friend_func.weight: " << weight << endl;
	}
};




int main()
{
/* 객체지향 없이 기존 코드 */
	string name;
	string address;
	int age;
	double height;
	double weight;

	printFriend(name, address, age, height, weight);

/* 데이터가 더 많은 경우 - array나 vector를 사용 */
	vector<string> name_vec;
	vector<string> address_vec;
	vector<int> age_vec;
	vector<double> height_vec;
	vector<double> weight_vec;

	printFriend(name_vec[0], address_vec[0],
		age_vec[0], height_vec[0], weight_vec[0]);



/* 구조체를 이용할 경우 */

//	Friend jj{ "Jack Jack" ,"Uptown" , 26, 173.2, 65.5 };
	Friend jj;
	jj.name = "Jack Jack";
	jj.age = 26;
	jj.address = "Uptown";
	jj.height = 173.2;
	jj.weight = 65.5;

	printFriend(jj.name, jj.address, jj.age, jj.height, jj.weight);
	printFriend(jj);

/* struct 안에 함수 넣기 */
	Friend_func cc;
	cc.printFriend();

	return 0;
}