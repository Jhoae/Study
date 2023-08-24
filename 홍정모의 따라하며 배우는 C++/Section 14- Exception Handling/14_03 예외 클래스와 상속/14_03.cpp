#include <iostream>
using namespace std;

/* #2 예외 class 만들기 */
class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

/* #3 Exception을 상속받는 class에서 주의사항 */
class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array exception" << endl;
	}
};


/* #1 */
class MyArray
{
private:
	int m_data[5];

public:
	int& operator[] (const int& index)
	{
/* #1 member function에서 exception을 throw할수 있다. */ 
		if (index < 0 || index >= 5) throw - 1;

		return m_data[index];
	}
};

/* #2 */
class MyArray_2
{
private:
	int m_data[5];

public:
	int& operator[] (const int& index)
	{
		if (index < 0 || index >= 5) throw Exception();

		return m_data[index];
	}
};


/* #3 */
class MyArray_3
{
private:
	int m_data[5];

public:
	int& operator[] (const int& index)
	{
		if (index < 0 || index >= 5) throw ArrayException();

		return m_data[index];
	}
};


/* #1 */
void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
}

/* #2 */
void doSomething_2()
{
	MyArray_2 my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	catch (Exception& e)
	{
		e.report();
	}
}


/* #3 */
void doSomething_3()
{
	MyArray_3 my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	catch (ArrayException& e)
	{
		cout << "doSomething()" << endl;
		e.report();
	}
	catch (Exception& e)
	{
		cout << "doSomething()" << endl;
		e.report();
	}
}


/* #4 re throw */
void doSomething_4()
{
	MyArray_3 my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	catch (ArrayException& e)
	{
		cout << "doSomething()" << endl;
		e.report();
		throw e;
	}
	catch (Exception& e)
	{
		cout << "doSomething()" << endl;
		e.report();
	}
}


/* #5  */
void doSomething_5()
{
	MyArray_3 my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	catch (Exception& e)
	{
		cout << "doSomething()" << endl;
		e.report();
		throw;
	}
}

int main()
{
	doSomething(); /* #1 */


	doSomething_2(); /* #2 */

	doSomething_3(); /* #3 */


	printf("\n#4\n");
/* #4 */
	try
	{ 
		doSomething_4();
	}
	catch(ArrayException & e)
	{
		cout << "main() catch" << endl;
		e.report();
	}



/* #5 */
	try
	{
		doSomething_5();
	}
	catch (ArrayException& e)
	{
		cout << "main() catch" << endl;
		e.report();
	}
	catch (Exception& e)
	{
		cout << "main() catch" << endl;
		e.report();
	}

	return 0;
}
