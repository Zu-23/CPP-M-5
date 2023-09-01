#include "Array.hpp"
#include<cstdlib>
#include<ctime>

int main(void)
{
   Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        arr[i] = i * 10;
    }

    try 
    {
        for (unsigned int i = 0; i < 10; i++)
        {
            std::cout << arr[i] << " ";
        }
    } 
    catch (const Boundlimit& e)
    {
        std::cout << e.what() << std::endl;
    }
}