/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:54:07 by dgauvin           #+#    #+#             */
/*   Updated: 2022/08/04 16:54:13 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void    Contact::set_index(int index)
{
    std::stringstream	ss;

	ss << index + 1;
	ss >> this->index;
}

void    Contact::set_firstname()
{
    std::cout << "Enter your first name: " << std::endl;
    std::getline(std::cin, first_name);
    check_eof();
}

void    Contact::set_lastname()
{
    std::cout << "Enter your last name: " << std::endl;
    std::getline(std::cin, last_name);  
    check_eof();  
}

void    Contact::set_nickname()
{
    std::cout << "Enter your nick name: " << std::endl;
    std::getline(std::cin, nickname);
    check_eof();  
}

void    Contact::set_phonenumber()
{
    std::cout << "Enter your phone number: " << std::endl;
    std::getline(std::cin, phone_number);
    check_eof();    
}

void    Contact::set_darkestsecret()
{
    std::cout << "Enter your darkest secret: " << std::endl;
    std::getline(std::cin, darkest_secret);
    check_eof();   
}

std::string    Contact::get_index()
{
    return (index);
}

std::string    Contact::get_firstname()
{
    return (first_name);
}

std::string    Contact::get_lastname()
{
    return (last_name);
}

std::string    Contact::get_nickname()
{
    return (nickname);
}

std::string    Contact::get_phonenumber()
{
    return (phone_number);
}

std::string    Contact::get_darkestsecret()
{
    return (darkest_secret);
}
