#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define BOOKSIZE 8
# define SEARCHSIZE 10

class PhoneBook{
	private:
			Contact	contacts[BOOKSIZE];
			int		index;
	public:
			PhoneBook();
			void	modify_contact();
			void	plus_index();
			void	print_contacts();
			bool	is_numeric(std::string &str);
};

#endif