#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator;
    typedef typename std::stack<T>::container_type::const_iterator;
    iterator begin()
    {
        return std::stack<T>::begin(); 
    }
    iterator end()
    {
        return std::stack<T>::end();
    }
    const_iterator begin() const
    {
        return std::stack<T>::begin();
    }
    const_iterator end() const
    { 
        return std::stack<T>::end(); 
    }
};
#endif