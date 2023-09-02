#include "Span.hpp"
#include<ctime>
#include<cstdlib>


int main()
{
    Span obj(10);
    std::srand((std::time(NULL)));
    try
    {
        // for(int i = 0; i < 10; i++)
        //     obj.addNumber(std::rand());
    obj.addNumber(4);
    obj.addNumber(10);
    obj.addNumber(2);
    obj.addNumber(8);
        std::cout << "shortest span: " << obj.shortestSpan() << std::endl;
        std::cout << "longest span: " << obj.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
        
    
}