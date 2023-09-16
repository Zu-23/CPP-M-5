#include <vector>
#include <iostream>

int main()
{
  try
  {
    std::vector<int> vec(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::vector<int>::iterator iter = vec.end();
    iter += 100;
    std::cout << *iter<< std::endl;
    int val = vec.at(343);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}
