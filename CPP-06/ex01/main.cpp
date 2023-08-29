#include "Serializer.hpp"

int main()
{ 
    Data dta;
    dta.str = "pointer casting";
    dta.n = 23;
    std::cout << dta.str << std::endl;
    std::cout << dta.n<< std::endl;
	std::cout << &dta << std::endl;
	// std::cout << "0x" << std::hex << Serializer::serialize(&dta) << std::endl;
	// std::cout << Serializer::deserialize(Serializer::serialize(&dta))->str << std::endl;
}