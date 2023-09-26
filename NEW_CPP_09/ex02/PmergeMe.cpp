/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:51:09 by zhaddoum          #+#    #+#             */
/*   Updated: 2023/09/26 15:00:52 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
    *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
    (void)rhs;
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/
void ft_perror(std::string str)
{
	std::cout << str << std::endl;
	exit(1);
}

void PmergeMe::validNum(char **av, int ac)
{
	for (int i = 1 ; i < ac; i++)
	{
		std::string str = av[i];
		for (size_t j = 0; j < str.size(); j++)
		{
			if (!std::isspace(str[j]) && !std::isdigit(str[j]))
				ft_perror("Invalid input");
		}
	}
}

void printTime(timeval start, timeval end, std::string std, size_t range)
{
    std::cout << "Time to process a range of " << range
    << " elements with std::" << std << " : "  
    << (end.tv_sec * 1e6 + end.tv_usec) - (start.tv_sec * 1e6 + start.tv_usec) << " us"
    << std::endl;
}
void printVector(std::vector<int> vec)
{
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void printDeque(std::deque<int> dq)
{
    std::deque<int>::iterator it;
    for (it = dq.begin(); it != dq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
void PmergeMe::parse_input(char **av, int ac)
{
	int val;
	timeval start;
	timeval end;

    std::vector<int> vec;
    std::deque<int> dq;
    validNum(av, ac);
    for (int i = 1 ; i < ac; i++)
	{
        int digit = 0;
		std::string str = av[i];
        for (size_t i = 0; i < str.size(); i++)
        {
            if (std::isdigit(str[i]))
                digit = 1;
        }
        if (digit == 0)
            continue;
        std::istringstream s(str);
        while (s >> val)
        {
            if (val < 0)
                ft_perror("Invalid input");
            vec.push_back(val);
            dq.push_back(val);
        } 
    }
    std::vector<int>::iterator it;
    std::cout << "before sort" << std::endl;
    for (it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << "after sort" << std::endl;

	gettimeofday(&start, NULL);
   	MergeSort_vector(vec, 0, vec.size() - 1);
	gettimeofday(&end, NULL);
    printVector(vec);
	printTime(start, end ,"vector<int>", vec.size());

	gettimeofday(&start, NULL);
   	MergeSort_dq(0, dq.size() - 1, dq);
	gettimeofday(&end, NULL);
    printTime(start, end, "deque<int>", dq.size());
    printDeque(dq);
}
//
//	--------------------DEQUE MERGE SORT-------------------

void PmergeMe::merge(int beg, int mid, int end, std::deque<int> &dq)
{
	int	n1 = mid - beg + 1;
	int	n2 = end - mid;
	int	ri = 0;
	int	li = 0;

	std::deque<int> left(dq.begin() + beg, dq.begin() + mid + 1);
	std::deque<int> right(dq.begin() + mid + 1, dq.begin() + end + 1);
   
    for (int i = beg; i <= end; i++)
	{
		if (ri == n2)
		{
			dq[i] = left[li];
			li++;
		}
		else if (li == n1)
		{
			dq[i] = right[ri];
			ri++;
		}
		else if (right[ri] > left[li])
		{
			dq[i] = left[li];
			li++;
		}
		else
		{
			dq[i] = right[ri];
			ri++;
		}
	}
}

void PmergeMe::MergeSort_dq(int beg, int end, std::deque<int> &dq)
{
    int treshold = 5;
	if (end - beg > treshold)
	{
		int	mid = (beg + end) / 2;
		MergeSort_dq(beg, mid, dq);
		MergeSort_dq(mid + 1, end, dq);
		merge(beg, mid, end, dq);
	}
	else
		sort(dq.begin(), dq.end());
}

//	--------------------VECTOR MERGE SORT-------------------

void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right)
{
    int lftsiz = mid - left + 1;
    int ritsiz = right - mid;
    std::vector<int> leftArr(lftsiz);
    std::vector<int> rightArr(ritsiz);

    for (int i = 0; i < lftsiz; ++i)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < ritsiz; ++i)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < lftsiz && j < ritsiz)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }
    while (i < lftsiz)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < ritsiz) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}
void PmergeMe::MergeSort_vector(std::vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort_vector(arr, left, mid);
        MergeSort_vector(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */