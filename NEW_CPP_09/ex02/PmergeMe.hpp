/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:51:12 by zhaddoum          #+#    #+#             */
/*   Updated: 2023/09/25 23:51:16 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
#include<vector>
#include<ctime>
#include<deque>
#include<algorithm>
#include <sys/time.h>


class PmergeMe
{
	private:
		void  validNum(char **av, int ac);
		//deque functions
		void merge(int beg, int mid, int end, std::deque<int> &dq);
		void MergeSort_dq(int beg, int end, std::deque<int> &dq);
		//vector functions
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