/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:54:41 by dgauvin           #+#    #+#             */
/*   Updated: 2022/08/04 16:54:51 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/directory.hpp"
#include <stdlib.h>

void	check_eof()
{
	if (std::cin.eof())
	{
		std::cout << "EOF" << std::endl;
		exit(1);
	}
}
int	main(void)
{
	PhoneBook	directory;
	std::string	action;

	while (directory.pursue)
	{
		std::cout << "Select your action (ADD, SEARCH, EXIT):" << std::endl;
		std::getline(std::cin, action);
		check_eof();
		if (!action.compare("ADD"))
			directory.add();
		else if (!action.compare("SEARCH"))
			directory.search();
		else if (!action.compare("EXIT"))
		{
			std::cout << "Exit directory" << std::endl;
			return (0);
		}
		else
			std::cout << "Please enter a valid action" << std::endl;
	}
	return (0);
}
