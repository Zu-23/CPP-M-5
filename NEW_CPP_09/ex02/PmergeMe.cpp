#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
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
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/
void PmergeMe::ft_perror(std::string str)
{
	std::cout << str << std::endl;
	exit(1);
}

int PmergeMe::validNum(char **av, int ac)
{
	for (size_t i = 1 ; i < ac; i++)
	{
		std::string str = av[i];
		for (size_t j = 0; j < str.size(); j++)
		{
			if (!std::isspace(str[j]) && !std::isdigit(str[j]))
				ft_perror("Invalid input");
		}

	}
}

void PmergeMe::parse_input(char **av, int ac)
{
	std::istringstream s()
	validNum(av, ac);// test with 2 digits

	
}

//	--------------------LIST MERGE SORT-------------------

void PmergeMe::merge(std::list<int>& arr, std::list<int>& leftArr, std::list<int>& rightArr)
{
    std::list<int>::iterator leftIt = leftArr.begin();
    std::list<int>::iterator rightIt = rightArr.begin();

    while (leftIt != leftArr.end() && rightIt != rightArr.end())
    {
        if (*leftIt <= *rightIt)
		{
            arr.push_back(*leftIt);
            ++leftIt;
        }
		else 
		{
            arr.push_back(*rightIt);
            ++rightIt;
        }
    }

    while (leftIt != leftArr.end())
    {
        arr.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != rightArr.end())
    {
        arr.push_back(*rightIt);
        ++rightIt;
    }
}

void PmergeMe::MergeSort_list(std::list<int>& arr)
{
    std::list<int> leftArr;
    std::list<int> rightArr;

    int mid = arr.size() / 2;
    std::list<int>::iterator it = arr.begin();
    for (int i = 0; i < mid; ++i)
    {
        leftArr.push_back(*it);
        ++it;
    }
    while (it != arr.end())
    {
        rightArr.push_back(*it);
        ++it;
    }
    MergeSort_list(leftArr);
    MergeSort_list(rightArr);
    arr.clear();
    merge(arr, leftArr, rightArr);
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