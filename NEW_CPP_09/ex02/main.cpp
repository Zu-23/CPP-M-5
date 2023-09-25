/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:50:55 by zhaddoum          #+#    #+#             */
/*   Updated: 2023/09/25 23:50:56 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac == 1)
        {
            std::cout << "3afak give some input" << std::endl;
            exit(1);
        }
        PmergeMe mrg;
        mrg.parse_input(av, ac);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}