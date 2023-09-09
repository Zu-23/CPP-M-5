#include<iostream>
#include<string>
#include<time.h>

void fo1()
{
    std::cout << "fo 1" << std::endl;
}

void fo2()
{
    std::cout << "fo 2" << std::endl;
}

void fo3()
{
        std::cout << "fo 3" << std::endl;

}
int main()
{
   void (*fo_ptr[3])(void) = {&fo1, &fo2, &fo3};
   (*fo_ptr[0])();
}
