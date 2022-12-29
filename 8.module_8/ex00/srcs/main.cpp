#include "../includes/Easyfind.Class.hpp"
#include <iostream>
#include <list>

void	ft_print(int i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	std::vector<int>	vct;
	std::list<int>		lst;
	
	for (int i = 0 ; i <= 42 ; i++)
		vct.push_back(i);

	try
	{
		std::vector<int>::iterator	it_vct = easyfind(vct, 34);
		for_each(it_vct, vct.end(), ft_print);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
