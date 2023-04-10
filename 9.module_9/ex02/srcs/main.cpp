#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe    pmm;
	
	std::cout << "Before: ";
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <set of numbers>" << std::endl;
		return 1;
	}
	else if (argv++ && argc == 2)
	{
		std::cout << *argv << std::endl;
		if (pmm.parse(*argv) == false)
			return (1);
	}
	else
	{
		if (pmm.parseList(argc, argv) == false)
			return (1);
	}

	pmm.sort_containers();
	pmm.print();
	
	std::cout << "Time to process a range of " << pmm.getVector().size() << " with std::vector : " << pmm.getElapsedVector() * 1000 << "ms" << std::endl;

	std::cout << "Time to process a range of " << pmm.getList().size() << " with std::list   : " << pmm.getElapsedList() * 1000 << "ms" << std::endl;

	return 0;
}
