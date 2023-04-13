#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe	pmm;
	
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <set of numbers>" << std::endl;
		return (1);
	}
	else if (argv++ && argc == 2)
	{
		try
		{
			pmm.parse(*argv);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		try
		{
			pmm.parseList(argc, argv);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			return (1);
		}
	}

	std::cout << "Before: ";
	std::list<int>::iterator	itBeg = pmm.getList().begin();
	std::list<int>::iterator	itEnd = pmm.getList().end();
	while (itBeg != itEnd)
	{
		std::cout << *itBeg << " ";
		++itBeg;
	}
	std::cout << std::endl;
	pmm.sort_containers();
	pmm.print();
	
	std::cout << "Time to process a range of " << pmm.getVector().size() << " with std::vector : " << pmm.getTimeVector() * 1000 << "ms" << std::endl;

	std::cout << "Time to process a range of " << pmm.getList().size() << " with std::list   : " << pmm.getTimeList() * 1000 << "ms" << std::endl;

	return (0);
}
