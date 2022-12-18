#include "../includes/Bureaucrat.Class.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat1("Jean", 1000);
		try
		{
			Bureaucrat bureaucrat2("Benoit", -15);
			for (int i = 0 ; i < 5 ; i++)
			{
				std::cout << bureaucrat2.getGrade() << std::endl;
				bureaucrat2.decrement();
			}
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		bureaucrat1.increment();
		try
		{
			for (int i = 0 ; i < 10 ; i++)
			{
				std::cout << bureaucrat1.getGrade() << std::endl;
				bureaucrat1.decrement();
			}
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << bureaucrat1.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
