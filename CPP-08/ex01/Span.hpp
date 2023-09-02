#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<algorithm>
#include<vector>
#include<stdexcept>

class Span
{
private:
    std::vector<int> vec;
    unsigned int N;

public:
    Span(unsigned int n);
    Span(const Span& obj);
    ~Span();
    Span& operator=(const Span& obj);

    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
};
#endif