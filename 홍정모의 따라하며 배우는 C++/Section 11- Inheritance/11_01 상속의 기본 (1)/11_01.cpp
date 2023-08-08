#include <iostream>
using namespace std;

class Mother
{
private:
// protected: -> 자식 class에서 접근 가능
	int m_i;

public:
/* #4 부모 class의 생성자 */
	/*
	Mother(const int& i_in)
		:m_i(i_in)
	{ 
		cout << "Mother Constructor" << endl;
	} 
	*/

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}

};

/* #1 Mother를 상속 받기 - Mother의 모든 것을 사용한다 
     ->  파생 클래스 derived class 생성  */  
class Child : public Mother 
{
/* #2 파생 클래스는 자신만의 무언가를 가질수 있다 */
private:
	double m_d;

public: 

	void setValue(const int& i_in, const double& d_in)
	{
		/* #3 상속할 떄 Mother class의 member에 접근하기 */
		// Error: m_i = i_in;->private이라면 자식 class에서도 접근 x
		// -> Mohter class의 setValue를 호출해서 사용 또는 protected
		Mother::setValue(i_in); 
		m_d = d_in;
	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}

};


/* #4 자식 class의 생성자 
	-> 부모 class의 m_i와 자식 class의 m_d를 함께 사용하기 위해서 작성 */
class Child_con : public Mother
{

private:
	double m_d;

public:
	Child_con(const int& i_in, const double& d_in)
		//	 :m_i(i_in), m_d(d_in) // Error -- m_i에 접근 불가능
	{
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const int& i_in, const double& d_in)
	{
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};


/* #5 부모 class의 생성자 작성 */
class Mother_con
{
private:
	int m_i;

public:
/* #5-1 간단하게 default 생성자 작성하여 상속구조를 간단히 할수도 있다 */
	Mother_con()
		:m_i(0)
	{}

/* #5-2 정밀하게 생성자 작성하여 상속구조를 명확히 할수도 있다 */
		Mother_con(const int& i_in)
			:m_i(i_in)
		{
			cout << "Mother_con Constructor" << endl;
		}

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}

};

class Child_Mcon : public Mother_con
{

private:
	double m_d;

public:
	Child_Mcon(const int& i_in, const double& d_in)
		:Mother_con(i_in), m_d(d_in)
	{}

	void setValue(const int& i_in, const double& d_in)
	{
		Mother_con::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};


int main()
{

	Mother mother;
	mother.setValue(1024);
	cout << "mother.getValue():\t" << mother.getValue() << endl;

	Child child;
	child.Mother::setValue(1024); // const int &
	child.setValue(128);          // const double &
	cout << "child.getValue():\t" << child.getValue() << endl;


	printf("\n#4\n");
/* #4 */
	Child_con child_c(2048, 256);
	cout << "child_c.Mother::getValue():\t" << child_c.Mother::getValue() << endl;
	cout << "child_c.getValue():\t" << child_c.getValue() << endl;
	

	printf("\n#5\n");
/* #5 */
	Child_Mcon child_Mc(4096, 512);
	cout << "child_Mc.Mother_con::getValue():\t" << child_Mc.Mother_con::getValue() << endl;
	cout << "child_Mc.getValue():\t" << child_Mc.getValue() << endl;

	return 0;
}