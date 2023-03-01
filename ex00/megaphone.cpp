/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:53:03 by dgauvin           #+#    #+#             */
/*   Updated: 2022/08/04 16:53:05 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
