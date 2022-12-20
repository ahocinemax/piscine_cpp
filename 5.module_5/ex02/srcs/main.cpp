#include "../includes/PresidentialPardonForm.Class.hpp"
#include "../includes/ShrubberyCreationForm.Class.hpp"
#include "../includes/RobotomyRequestForm.Class.hpp"
#include "../includes/Bureaucrat.Class.hpp"
#include "../includes/Form.Class.hpp"

int main()
{
	Bureaucrat john("\e[34mJohn\e[0m", 5);

	PresidentialPardonForm a("\e[31mPPF\e[0m");
	ShrubberyCreationForm b("\e[33mSCF\e[0m");
	RobotomyRequestForm c("\e[32mRRF\e[0m");

	std::cout << john << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	john.signForm(a);

	john.signForm(b);
	john.signForm(b); // cant sign because already signed
	
	john.signForm(c);
	a.action(john);
	b.action(john);
	c.action(john);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}