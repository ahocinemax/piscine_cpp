#include "../includes/Bureaucrat.Class.hpp"

int	main(void)
{
	Bureaucrat bureaucrat1("Jean", 10);
	try
	{
		Bureaucrat bureaucrat2("Benoit", 15);
		for (int i = 0 ; i < 5 ; i++)
		{
			bureaucrat2.getGrade();
			bureaucrat2.toTheFomo();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	bureaucrat1.toTheMoon();
	try
	{
		for (int i = 0 ; i < 10 ; i++)
		{
			bureaucrat1.getGrade();
			bureaucrat1.toTheFomo();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat1.getGrade() << std::endl;
	return (0);
}
