#include "../includes/PresidentialPardonForm.Class.hpp"
#include "../includes/ShrubberyCreationForm.Class.hpp"
#include "../includes/RobotomyRequestForm.Class.hpp"
#include "../includes/Bureaucrat.Class.hpp"
#include "../includes/Form.Class.hpp"

int main()
{
	Bureaucrat john("John", 5);

	std::cout << john << std::endl;

	try
	{
		john.increment();
		john.decrement();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	PresidentialPardonForm a("a");
	ShrubberyCreationForm b("b");
	RobotomyRequestForm c("c");
	std::cout << john << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	john.signForm(a);
	john.signForm(b);
	john.signForm(b);
	
	try
	{
		john.decrement();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	john.signForm(c);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}