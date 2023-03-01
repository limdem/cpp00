/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:58:04 by dgauvin           #+#    #+#             */
/*   Updated: 2022/08/04 16:58:06 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "directory.hpp"
# include "Contact.hpp"
# include <iostream>
# include <sstream> 

class PhoneBook
{
		int	count;
		int	index;
		Contact	book[8];
		void	enter_info(Contact*, void(Contact::*)(), std::string(Contact::*)(), int);
		void	display_contact_info(std::string, int);
		void	display_perso_info();
	public:
		PhoneBook();
		int	pursue;
		void	add(void);
		void	search(void);
};

#endif
