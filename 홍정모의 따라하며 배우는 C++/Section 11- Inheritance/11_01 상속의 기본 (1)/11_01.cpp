#include <iostream>
using namespace std;

class Mother
{
private:
// protected: -> �ڽ� class���� ���� ����
	int m_i;

public:
/* #4 �θ� class�� ������ */
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

/* #1 Mother�� ��� �ޱ� - Mother�� ��� ���� ����Ѵ� 
     ->  �Ļ� Ŭ���� derived class ����  */  
class Child : public Mother 
{
/* #2 �Ļ� Ŭ������ �ڽŸ��� ���𰡸� ������ �ִ� */
private:
	double m_d;

public: 

	void setValue(const int& i_in, const double& d_in)
	{
		/* #3 ����� �� Mother class�� member�� �����ϱ� */
		// Error: m_i = i_in;->private�̶�� �ڽ� class������ ���� x
		// -> Mohter class�� setValue�� ȣ���ؼ� ��� �Ǵ� protected
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


/* #4 �ڽ� class�� ������ 
	-> �θ� class�� m_i�� �ڽ� class�� m_d�� �Բ� ����ϱ� ���ؼ� �ۼ� */
class Child_con : public Mother
{

private:
	double m_d;

public:
	Child_con(const int& i_in, const double& d_in)
		//	 :m_i(i_in), m_d(d_in) // Error -- m_i�� ���� �Ұ���
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


/* #5 �θ� class�� ������ �ۼ� */
class Mother_con
{
private:
	int m_i;

public:
/* #5-1 �����ϰ� default ������ �ۼ��Ͽ� ��ӱ����� ������ �Ҽ��� �ִ� */
	Mother_con()
		:m_i(0)
	{}

/* #5-2 �����ϰ� ������ �ۼ��Ͽ� ��ӱ����� ��Ȯ�� �Ҽ��� �ִ� */
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