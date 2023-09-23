#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
#include<list>
#include<vector>

class PmergeMe
{
	private:
        std::vector<int> vec;
        std::list<int> lst;

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );


};

#endif /* ******************************************************** PMERGEME_H */