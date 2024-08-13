#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	std::string	cmd;
	std::string index;
	PhoneBook book;

	while (true)
	{
		std::cout<<"input command[ADD, SEARCH, EXIT]"<<std::endl;
		while(!(std::getline(std::cin, cmd)))
		{
			clearerr(stdin);
			std::cin.clear();
		}
		if (cmd.compare("ADD") == 0)
			book.modify_contact();
		else if (cmd.compare("SEARCH") == 0)
		{
			book.print_contacts();
			//index 예외체크(숫자 아닌거나 목록에 없는 것들 예외처리)
			//index에 해당하는 연락처 표시
		}
		else if (cmd.compare("EXIT") == 0)
		{
			std::cout<<"---EXIT---"<<std::endl;
			return (0);
		}
		else
			std::cout<<"[Error] : invalid command!!!"<<std::endl;
	}
}