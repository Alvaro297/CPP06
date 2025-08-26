#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>

Base *generate()
{
	int num = (std::rand() % 3) + 1;
	
	if(num == 1)
		return new A();
	else if (num == 2)
		return new B();
	else
		return new C();
}

int main()
{

}