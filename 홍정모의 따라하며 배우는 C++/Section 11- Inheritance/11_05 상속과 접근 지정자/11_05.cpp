#include <iostream>
using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};


/* #2 */
class Derived_public : public Base
{
public:
	Derived_public()
	{
		m_public = 123;     // OK
		m_protected = 123;  // OK
		// Error: m_private = 123;
	}

};

/* #3 */
class Derived_protected : protected Base
{
public:
	Derived_protected()
	{
		Base::m_public = 123;
		Base::m_protected = 123;
		// Error: Base::m_private = 123;
	}
};



/* #4 */
class Derived_private: private Base
{
public:
	Derived_private()
	{
		Base::m_public = 123;
		Base::m_protected = 123;
		// Error: Base::m_private = 123;
	}
};

class GrandChild : public Derived_private
{
public:
	GrandChild()
	{
		// Error: Derived_private::m_public = 123;
		// Error: Derived_private::m_protected = 123;
		// Error: Derived_private::m_private = 123;
	}
};


int main()
{
/* #1 */
	Base base;

	base.m_public = 123; // OK
	// Error: base.m_protected = 123; 
	// Error: base.m_private = 123; 

/* #2 */
	Derived_public derived_pub;
	derived_pub.m_public = 1024;
	// Error: derived_pub.m_protected = 1024;
	// Error: derived_pub.m_private = 1024;


/* #3 */
	Derived_protected derived_pro;
	// Error: derived_pro.m_public = 1024;
	// Error: derived_pro.m_protected = 1024;
	// Error: derived_pro.m_private = 1024;

	return 0;
}