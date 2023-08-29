#include "Base.hpp"

Base * generate(void)
{
	int ret = rand() % 3;
	if (ret == 0)
		return static_cast<Base *>(new A());
	else if (ret == 1)
		return static_cast<Base *>(new B());
	else
		return static_cast<Base *>(new C());
}

void identify(Base * p)
{
	A * a = dynamic_cast<A *>(p);
	B * b = dynamic_cast<B *>(p);
	C * c = dynamic_cast<C *>(p);
	if (a)
		print("A");
	else if (b)
		print("B");
	else if (c)
		print("C");
	else
		std::cout << "Can not identify this type" << std::endl;
}

void identify_from_reference(Base & p)
{
	try {
		A & a = dynamic_cast<A &>(p);
		a.print();
	}
	catch (std::exception &e){
	}
	try {
		B & b = dynamic_cast<B &>(p);
		b.print();
	}
	catch (std::exception &e){
	}
	try {
		C & c = dynamic_cast<C &>(p);
		c.print();
	}
	catch (std::exception &e){
	}
}