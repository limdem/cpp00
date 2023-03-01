/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:57:47 by dgauvin           #+#    #+#             */
/*   Updated: 2022/08/04 16:57:50 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

//# include "directory.hpp"
# include <sstream>
# include <iostream>
# include <string>
# include <stdlib.h>

class Contact
{
		std::string	index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void	set_index(int);
		void	set_firstname();
		void	set_lastname();
		void	set_nickname();
		void	set_phonenumber();
		void	set_darkestsecret();
		std::string	get_index();
		std::string	get_firstname();
		std::string	get_lastname();
		std::string	get_nickname();
		std::string	get_phonenumber();
		std::string	get_darkestsecret();
};

void	check_eof();
#endif
