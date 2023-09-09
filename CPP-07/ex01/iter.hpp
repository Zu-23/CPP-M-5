#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>

template<typename T, typename Foo>
void iter(T *arr, size_t size, Foo foo)
{
	for (size_t i = 0; i < size; i++)
		foo(arr[i]);
}

template <typename T>
void printElement(T& element)
{
    std::cout << element << " ";
}

#endif