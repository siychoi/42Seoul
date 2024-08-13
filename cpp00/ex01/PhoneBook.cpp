#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}
bool	PhoneBook::is_numeric(std::string &str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void	PhoneBook::modify_contact()
{
	std::string	firstname, lastname, nickname, number, secret;

	std::cout << std::endl << "-----[ADD]-----" << std::endl;
	std::cout << "input first name: " << std::endl;
	while(!(std::getline(std::cin, firstname)) || firstname.empty())
	{
		clearerr(stdin);
		std::cin.clear();
	}
	contacts[this->index].set_first_name(firstname);

	std::cout << "input last name: " << std::endl;
	while(!(std::getline(std::cin, lastname)) || lastname.empty())
	{
		clearerr(stdin);
		std::cin.clear();
	}
	contacts[this->index].set_last_name(lastname);

	std::cout << "input nickname: " << std::endl;
	while(!(std::getline(std::cin, nickname)) || nickname.empty())
	{
		clearerr(stdin);
		std::cin.clear();
	}
	contacts[this->index].set_nickname(nickname);

	while(true)
	{
		std::cout << "input phone number: " << std::endl;
		while(!(std::getline(std::cin, number)) || number.empty())
		{
			clearerr(stdin);
			std::cin.clear();
		}
		if (is_numeric(number))
			break ;
		else
			std::cout << "[Error] : you have to input only numbers!!!" << std::endl;
	}
	contacts[this->index].set_phone_number(number);

	std::cout << "input darkest secret: " << std::endl;
	while(!(std::getline(std::cin, secret)) || secret.empty())
	{
		clearerr(stdin);
		std::cin.clear();
	}
	contacts[this->index].set_darkest_secret(secret);

	plus_index();
}

void	PhoneBook::plus_index()
{
	this->index = this->index + 1;
	if (this->index >= BOOKSIZE)
		this->index = 0;
}

void	PhoneBook::print_contacts()
{
	int	j = 0;

	if (contacts[j].get_first_name().empty())
	{
		std::cout << "[Error] : PhoneBook is empty, add contacts first!!!" << std::endl;
		return ;
	}

	std::cout << std::endl << "-----[SEARCH]-----" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "| index | firstname| lastname | nickname |" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	while(!contacts[j].get_first_name().empty())
	{
		std::cout << "|      " << j << "|"; //index 출력

		//first name
		if (contacts[j].get_first_name().size() > 10)
		{
			for (size_t i = 0; i < 9; i++)
			{
				if (!isprint((contacts[j].get_first_name())[i]))
					std::cout << " ";
				else
					std::cout << (contacts[j].get_first_name())[i];
			}
			std::cout<<".|";
		}
		else
		{
			for (size_t i = 0; i < SEARCHSIZE - contacts[j].get_first_name().size(); i++)
				std::cout << " ";
			
			for (size_t i = 0; i < contacts[j].get_first_name().size(); i++)
			{
				if (!isprint((contacts[j].get_first_name())[i]))
					std::cout << " ";
				else
					std::cout << (contacts[j].get_first_name())[i];
			}
			std::cout << "|";
		}

		//last name
		if (contacts[j].get_last_name().size() > 10)
		{
			for (size_t i = 0; i < 9; i++)
			{
				if (!isprint((contacts[j].get_last_name())[i]))
					std::cout << " ";
				else
					std::cout << (contacts[j].get_last_name())[i];
			}
			std::cout<<".|";
		}
		else
		{
			for (size_t i = 0; i < SEARCHSIZE - contacts[j].get_last_name().size(); i++)
				std::cout << " ";
			for (size_t i = 0; i < contacts[j].get_last_name().size(); i++)
			{
				if (!isprint((contacts[j].get_last_name())[i]))
					std::cout << " ";
				else
					std::cout << (contacts[j].get_last_name())[i];
			}
			std::cout << "|";
		}

		//nickname
		if (contacts[j].get_nickname().size() > 10)
		{
			for (size_t i = 0; i < 9; i++)
			{
				if (!isprint((contacts[j].get_nickname())[i]))
					std::cout << " ";
				else
					std::cout << (contacts[j].get_nickname())[i];
			}
			std::cout << ".|" << std::endl;
		}
		else
		{
			for (size_t i = 0; i < SEARCHSIZE - contacts[j].get_nickname().size(); i++)
				std::cout << " ";
			for (size_t i = 0; i < contacts[j].get_nickname().size(); i++)
			{
				if (!isprint((contacts[j].get_nickname())[i]))
					std::cout << " ";
				else
					std::cout << (contacts[j].get_nickname())[i];
			}
			std::cout << "|" << std::endl;
		}

		std::cout << "------------------------------------------" << std::endl;
		j++;
		if (j >= BOOKSIZE)
			break ;
	}
	
	int	index;
	std::string	indexStr;
	while(true)
	{
		std::cout << std::endl << "input [index] you want" << std::endl;
		while(!(std::getline(std::cin, indexStr)) || indexStr.empty())
		{
			clearerr(stdin);
			std::cin.clear();
		}
		if (indexStr.length() == 1 && is_numeric(indexStr))
		{
			index = atoi(indexStr.c_str());
			if (index < BOOKSIZE)
				break ;
		}
		std::cout << "[Error] : you have to input only number less than 8!!!" << std::endl;
	}
	if (!contacts[index].get_first_name().empty())
	{
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "first name : " << contacts[index].get_first_name() << std::endl
					<< "last name : " << contacts[index].get_last_name() << std::endl
					<< "nickname : " << contacts[index].get_nickname() << std::endl
					<< "phone number : " << contacts[index].get_phone_number() << std::endl
					<< "darkest secret : " << contacts[index].get_darkest_secret() << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
	}
	else
	{
		std::cout << "[Error] : you have to input vaild index!!!" << std::endl;
		return ;
	}
}