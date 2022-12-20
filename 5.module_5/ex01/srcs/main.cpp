#include "../includes/Bureaucrat.Class.hpp"
#include "../includes/Form.Class.hpp"

int main()
{
	Bureaucrat john("\e[33mJohn\e[0m", 5);


	try
	{
		john.increment();
		std::cout << john << std::endl;
		john.decrement();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << john << std::endl;
	
	try
	{
		john.decrement();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form *module5 = new Form("\e[35minscription\e[0m", 13, 82);
		if (module5->getIsSigned())
			std::cout << module5->getName() << " \e[32mis signed\e[0m." << std::endl;
		else
			std::cout << module5->getName() << " \e[31mis not signed.\e[0m" << std::endl;
		module5->beSigned(john);
		if (module5->getIsSigned())
			std::cout << module5->getName() << " \e[32mis signed\e[0m." << std::endl;
		else
			std::cout << module5->getName() << " \e[31mis not signed.\e[0m" << std::endl;
		delete module5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}