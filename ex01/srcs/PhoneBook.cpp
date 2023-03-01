/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:54:59 by dgauvin           #+#    #+#             */
/*   Updated: 2022/08/04 16:55:01 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	count = 0;
	index = 0;
	pursue = 1;
}

void	PhoneBook::enter_info(Contact *contact, void (Contact::*fset)(), std::string (Contact::*fget)(), int type)
{
	int	i;
	std::string	info;
	i = 0;

	(contact->*fset)();
	info = (contact->*fget)();
	while (info[i])
	{
		if ((!std::isalpha(info[i]) && !type) ||
				((!std::isdigit(info[i]) || info.length() != 10) && type == 2 ))
		{
			std::cout << "You entered a wrong input" << std::endl;
			enter_info(contact, fset, fget, type);
			return ;
		}
		i++;
	}
}

void	PhoneBook::add()
{
	book[index].set_index(index);
	enter_info(&book[index], &Contact::set_firstname, &Contact::get_firstname, 0);
	enter_info(&book[index], &Contact::set_lastname, &Contact::get_lastname, 0);
	enter_info(&book[index], &Contact::set_nickname, &Contact::get_nickname, 1);
	enter_info(&book[index], &Contact::set_phonenumber, &Contact::get_phonenumber, 2);
	enter_info(&book[index], &Contact::set_darkestsecret, &Contact::get_darkestsecret, 1);
	if (index < 8)
	{
		if (count < 8)
			count++;
		if (index == 7)
			index = 0;
		else
			index++;
	}
}

void	PhoneBook::display_contact_info(std::string info, int endline)
{
	int	i;
	int	len;
	int	start;

	i = -1;
	len = info.length();
	start = 10 - len;
	if (start < 0)
		start = 0;
	while (++i < 10)
	{
		if (len > 10 && i == 9)
		{
			std::cout << '.';
			break ;
		}
		if (i >= start)
			std::cout << info[i - start];
		else
			std::cout << ' ';
	}
	if (endline)
		std::cout << std::endl;
	else
		std::cout << '|';
}

void	PhoneBook::display_perso_info()
{
	std::string	select;
	int	i;

	std::cout << "Select a contact (enter the index):" << std::endl;
    std::getline(std::cin, select);
	check_eof();
	if (!(select[0] >= 49 && select[0] - 48 <= count && select.length() == 1))
	{
		std::cout << "You entered a wrong index" << std::endl;
		return (display_perso_info());
	}
	i = select[0] - 48 - 1;
	std::cout << "Contact information:" << std::endl;
	std::cout << book[i].get_firstname() << std::endl;
	std::cout << book[i].get_lastname() << std::endl;
	std::cout << book[i].get_nickname() << std::endl;
	std::cout << book[i].get_phonenumber() << std::endl;
	std::cout << book[i].get_darkestsecret() << std::endl;
}

void	PhoneBook::search()
{
	int	i;

	i = 0;
	
	display_contact_info("INDEX", 0);
	display_contact_info("FIRST NAME", 0);
	display_contact_info("LAST NAME", 0);
	display_contact_info("NICK NAME", 1);
	if (!count)
	{
		std::cout << "There is currently no contact in the phonebook" << std::endl;
		return ;
	}
	while (i < count)
	{
		display_contact_info(book[i].get_index(), 0);
		display_contact_info(book[i].get_firstname(), 0);
		display_contact_info(book[i].get_lastname(), 0);
		display_contact_info(book[i].get_nickname(), 1);
		i++;
	}
	display_perso_info();	
}
