#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
#include<vector>
#include<ctime>
#include<deque>
#include<algorithm>
#include <sys/time.h>
//BRING BACK THE FLAGSSSS
class PmergeMe
{
	private:
        std::vector<int> vec;
        std::list<int> lst;
		void  validNum(char **av, int ac);
		void merge(std::list<int>& arr, std::list<int>& leftArr, std::list<int>& rightArr);
		void MergeSort_list(std::list<int>& arr);
		void merge(std::vector<int>& arr, int left, int mid, int right);
		void MergeSort_vector(std::vector<int>& arr, int left, int right);
	public:
		void parse_input(char **av, int ac);
		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );


};
void 		printTime(timeval start, timeval end, std::string std, size_t range);
void 		ft_perror(std::string str);

#endif /* ******************************************************** PMERGEME_H */