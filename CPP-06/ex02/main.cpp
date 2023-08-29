#include "Base.hpp"


int main(void)
{
	Base *p1;
	Base *p2;
	Base *p3;
	A r1;
	B r2;
	C r3;
		

	p1 = generate();
	p2 = generate();
	p3 = generate();

	std::cout << "Pointers: " << std::endl;
	identify(p1);
	identify(p2);
	identify(p3);

	
	std::cout << "Refrences" <<  std::endl;
	identify(r1);
	identify(r2);
	identify(r3);
}
