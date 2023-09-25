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
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
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
    << (end.tv_sec * 1e6 + end.tv_usec) - (start.tv_sec * 1e6 + start.tv_usec)
    << "us";
}
void printVector(std::vector<int> vec)
{
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}


void printList(std::list<int> lst)
{
    std::list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}



void PmergeMe::parse_input(char **av, int ac)
{
	int val;
	timeval start;
	timeval end;

    std::vector<int> vec;
    std::list<int> lst;
    validNum(av, ac);
    for (int i = 1 ; i < ac; i++)
	{
		std::string str = av[i];
        val = std::atoi(str.c_str());
        if (val < 0)
            ft_perror("Invalid input");
        vec.push_back(val);
        lst.push_back(val);
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

	//gettimeofday(&start, NULL);
   	MergeSort_list(lst);
	//gettimeofday(&end, NULL);
    // printList(lst);
    // printTime(start, end, "list<int>", lst.size());
	
	
}

//	--------------------LIST MERGE SORT-------------------

void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void PmergeMe::MergeSort_list(std::vector<int>& arr) {
    int n = arr.size();

    for (int currSize = 1; currSize <= n - 1; currSize *= 2)
    {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = std::min(leftStart + currSize - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * currSize - 1, n - 1);
            merge(arr, leftStart, mid, rightEnd);
        }
    }
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