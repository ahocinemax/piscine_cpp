#include "../includes/Iter.Class.hpp"

int	main(void)
{
	std::string	array[] = {"bonjour", "hola", "konichiwa"};
	::iter(array, 3, ft_print<std::string>);

	std::cout << std::endl;

	char	str[] = "Ceci est un test";
	::iter(str, 17, ft_print);

	std::cout << std::endl;

	float	test[] = {14.3f, 115.73, 124.0f};
	::iter(test, 3, ft_print);
	return (0);
}