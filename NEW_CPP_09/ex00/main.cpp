/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:51:47 by zhaddoum          #+#    #+#             */
/*   Updated: 2023/09/25 23:51:48 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            std::cout << "Error: wrong number of arguments\nUsage: ./btc <file_name>" << std::endl;
            return (1);
        }
        else
        {
            Bitcoin btc;
            btc.parse_file(av[1]);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
     
    return (0);
    }