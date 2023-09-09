#include "Span.hpp"

Span::Span(unsigned int n) : N(n)
{
    vec.reserve(this->N);
}

Span::~Span()
{
}

Span::Span(const Span &obj) : N(0), vec(NULL)
{
	std::cout << "Copy constructor" << std::endl;
	*this = obj;
}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
    {
        this->N = obj.N;
        this->vec.clear();
        for (int i = 0; i < obj.vec.size(); i++) 
            this->vec.push_back(obj.vec[i]); 
    }
}

void Span::addNumber(int num)
{
    if (vec.size() >= N)
        throw std::runtime_error("Capacity is full!");
    this->vec.push_back(num);
}

int Span::shortestSpan()
{
    if (vec.size() <= 1)
        throw std::runtime_error("too few numbers to calculate span");
    std::sort(vec.begin(), vec.end());
    int min = vec[1] - vec[0];
    for (size_t i = 2; i < vec.size(); ++i)
    {
        int span = vec[i] - vec[i - 1];
        if (span < min)
            min = span;
    }
    return min;
}

int Span::longestSpan() {
    if (vec.size() <= 1)
        throw std::runtime_error("too few numbers to calculate span");
    std::sort(vec.begin(), vec.end());
    int res = vec[vec.size() - 1] - vec[0];
    return (res);
}

void Span::spanIter(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (this->vec.size() + std::distance(begin, end) > this->N)
        throw std::runtime_error("this range exceeds the vector's space");
    vec.insert(vec.end(), begin, end);
}