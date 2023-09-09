#include <vector>
#include <iostream>

int main()
{

   std::vector<char> vet;
   vet.reserve(3);
   vet.push_back('a');
   std::cout << vet.size() << std::endl;

   std::vector<char>::const_iterator it;
   it = vet.cbegin();
   while (it != vet.cend())
   {
     std::cout << *it << std::endl;
     it++;
   }
}