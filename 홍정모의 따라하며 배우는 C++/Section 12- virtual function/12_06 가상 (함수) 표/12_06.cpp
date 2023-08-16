#include <iostream>
using namespace std;

class Base
{
public:
	// FunctionPointer* __vptr;
	virtual void func1() {};
	virtual void func2() {};
};

class Der :public Base
{
public:
	// FunctionPointer* __vptr;
	virtual void func1() {};
	virtual void func3() {};
};


int main()
{
	cout << "sizeof(Base):\t" << sizeof(Base) << endl;
	cout << "sizeof(Der):\t" << sizeof(Der) << endl;
	

	// virtual이 없을경우 1bytes / 1bytes
	// x86에서 virtual일경우 4bytes / 4bytes
	// x64에서 virtual일경우 8bytes / 8bytes

	return 0;
}