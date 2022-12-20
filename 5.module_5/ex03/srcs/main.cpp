#include "../includes/PresidentialPardonForm.Class.hpp"
#include "../includes/ShrubberyCreationForm.Class.hpp"
#include "../includes/RobotomyRequestForm.Class.hpp"
#include "../includes/Bureaucrat.Class.hpp"
#include "../includes/Intern.Class.hpp"
#include "../includes/Form.Class.hpp"

int main()
{
	Bureaucrat john("John", 5);

	PresidentialPardonForm a("a");
	ShrubberyCreationForm b("b");
	RobotomyRequestForm c("c");
	
	john.signForm(c);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}