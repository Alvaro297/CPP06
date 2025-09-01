#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>
#include <iostream>
#include <typeinfo>
#include <ctime>
#include <cstdlib>

Base *generate()
{
	int num = std::rand() % 3;

	if (num == 0)
		return new A();
	else if (num == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	A* aClass = dynamic_cast<A*>(p);
	B* bClass = dynamic_cast<B*>(p);
	C* cClass = dynamic_cast<C*>(p);
	if (aClass)
		std::cout << "The class is A" << std::endl;
	else if (bClass)
		std::cout << "The class is B" << std::endl;
	else if (cClass)
		std::cout << "The class is C" << std::endl;
	else
		std::cerr << "Something went wrong: unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &aClass = dynamic_cast<A&>(p);
		(void)aClass;
		std::cout << "The class is A" << std::endl;
		return;
	}
	catch (std::exception e)
	{}

	try
	{
		B &bClass = dynamic_cast<B&>(p);
		(void)bClass;
		std::cout << "The class is B" << std::endl;
		return;
	}
	catch (std::exception e)
	{}

	try
	{
		C &cClass = dynamic_cast<C&>(p);
		(void)cClass;
		std::cout << "The class is C" << std::endl;
		return;
	}
	catch (std::exception e)
	{}

	std::cerr << "Something went wrong: unknown reference type" << std::endl;
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 5; ++i)
	{
		Base* p = generate();

		std::cout << "[Test " << i + 1 << "] Pointer identification: ";
		identify(p);
		std::cout << "[Test " << i + 1 << "] Reference identification: ";
		identify(*p);
		delete p;
		std::cout << "-----------------------------" << std::endl;
	}
	return 0;
}
