#include<iostream>
#include<string>
#include<vector>
#include<list>



void merge(std::list<int>& arr, std::list<int>& leftArr, std::list<int>& rightArr)
{
    std::list<int>::iterator leftIt = leftArr.begin();
    std::list<int>::iterator rightIt = rightArr.begin();

    while (leftIt != leftArr.end() && rightIt != rightArr.end())
    {
        if (*leftIt <= *rightIt) {
            arr.push_back(*leftIt);
            ++leftIt;
        } else {
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

// Merge-sort function for lists
void mergeSort(std::list<int>& arr)
{
    if (arr.size() <= 1) {
        return;
    }

    std::list<int> leftArr;
    std::list<int> rightArr;
    int mid = arr.size() / 2;

    // Split the list into two sublists
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

    // Recursively sort the sublists
    mergeSort(leftArr);
    mergeSort(rightArr);

    // Merge the sorted sublists
    arr.clear();
    merge(arr, leftArr, rightArr);
}




void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int lftsiz = mid - left + 1;
    int ritsiz = right - mid;
    std::vector<int> leftArr(lftsiz);
    std::vector<int> rightArr(ritsiz);

    for (int i = 0; i < lftsiz; ++i)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < ritsiz; ++i) {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < lftsiz && j < ritsiz) {
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

//3 5 1 7

void MergeSort_vector(std::vector<int>& arr, int left, int right)
{
    //1- left = 0. right = 3. mid = 1
    //2- left = 0. right = 1. mid = 0 >> 2.1 left = 1. right = 1 << return (2)
    //2->merge: left = 0, mid = 0, right = 1
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort_vector(arr, left, mid);
        MergeSort_vector(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void validNum(char **av, int ac)
{
	for (size_t i = 1 ; i < ac; i++)
	{
		std::string str = av[i];
        if (str.empty())
            continue;
		for (size_t j = 0; j < str.size(); j++)
		{
			if (!std::isspace(str[j]) && !std::isdigit(str[j]))
            {
				std::cout << "Invalid input\n";
                exit(1);
            }
		}

	}
}

void parse_input (char **av, int ac)
{
    int val;
    std::vector<int> vec;
    std::list<int> lst;
    for (size_t i = 1 ; i < ac; i++)
	{
		std::string str = av[i];
        val = std::atoi(str.c_str());
        if (val < 0)
            std::cout << "Invalid arguemnt\n";
        vec.push_back(val);
        lst.push_back(val);
    }
    std::vector<int>::iterator it;
    std::cout << "before sort" << std::endl;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "after sort" << std::endl;
   MergeSort_vector(vec, 0, vec.size() - 1);
    for (it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
   // MergeSort_list(lst)
}

int main(int ac, char **av)
{
    int val;

    validNum(av, ac);
    parse_input(av, ac);
    
}