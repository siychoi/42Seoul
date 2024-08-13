#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

class Contact {
	private:
			std::string	first_name;
			std::string	last_name;
			std::string	nickname;
			std::string	phone_number;
			std::string	darkest_secret;
	public:
			std::string	get_first_name();
			std::string	get_last_name();
			std::string	get_nickname();
			std::string	get_phone_number();
			std::string	get_darkest_secret();
			void	set_first_name(std::string);
			void	set_last_name(std::string);
			void	set_nickname(std::string);
			void	set_phone_number(std::string);
			void	set_darkest_secret(std::string);
};

#endif
