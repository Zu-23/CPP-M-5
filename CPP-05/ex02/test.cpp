#include<iostream>
#include<string>


class base
{
    protected:
        int a;
    public:
        base(int i)
        {
            a = i;
        }
        virtual void pure_fo()= 0;
};

class derived : public base
{
    private:
        int b;
    public:
        derived(int i, int j) : base(i)
        {
            pure_fo();
        }
        void pure_fo()
        {
            std::cout << "what the value of a? " << a << std::endl;
        }
};

int main()
{
    derived obj(3, 5);
}