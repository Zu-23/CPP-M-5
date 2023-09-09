#include<iostream>
#include<string>
#include<time.h>

class Abstract
{
public:
  virtual void foo() = 0;
};

class Implementation : public Abstract
{
public:
  void foo() { std::cout << "Foo!" << std::endl; }
};

void call_foo(Abstract& obj) { obj.foo(); } 


class pure
{
    public:
        void    execute(Abstract &obj)
        {
            try
            {
                std::cout  << "whaat" << std::endl;
                obj.foo();

            }
            catch(...)
            {
                std::cout << "okay " << std::endl;
            }
        }
};

int main()
{
    std::cout << "start pf test" << std::endl;
    throw("some error");
    std::cout << "did it" << std::endl;
}
