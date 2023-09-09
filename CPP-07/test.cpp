#include <iostream>

template <typename T>
class Storage
{
private:
    T m_value;
public:
    Storage(T value)
      : m_value (value )
    {
    }

    void print()
    {
        std::cout << m_value << '\n';
    }
};

template <>
void Storage<double>::print()
{
    std::cout << std::scientific << m_value << '\n';
}
template<>
Storage<char *>::Storage(char * value)
{
    this->m_value = value;
    std::cout << value << std::endl;
}

int main()
{
   
   int *a = new int[4]();
   a = NULL;
   delete []a;
//    for(int i = 0; i < 4; i++)
//    {
//         a[i] = i;

//    }
//    for(int i = 0; i < 4; i++)
//    {
//    std::cout << a[i] << std::endl;
//    }
}