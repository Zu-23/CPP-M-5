#include <iostream>
#include <utility>

int main() {
    // Creating a pair with an integer and a double
    std::pair<int, double> myPair(42, 3.14);

    // Accessing the elements of the pair
    int intValue = myPair.first;
    double doubleValue = myPair.second;

    // Printing the values
    std::cout << "First value: " << intValue << std::endl;
    std::cout << "Second value: " << doubleValue << std::endl;

    return 0;
}
