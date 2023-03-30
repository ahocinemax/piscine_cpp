#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(int argc, char** argv)
{
    PmergeMe    list;
    clock_t     start, end;
    
	std::cout << "Before: ";
    start = clock();
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe <set of numbers>" << std::endl;
        return 1;
    }
    else if (argv++ && argc == 2)
    {
        if (list.parse(*argv) == false)
            return (1);
    }
    else
    {
        if (list.parseList(argc, argv) == false)
            return (1);
    }

    list.print();
    srand(time(NULL));
    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << list.size() << " with std::set: " << elapsed * 1000 << "ms" << std::endl;

    start = clock();
    PmergeMe lst(*argv);
    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << list.size() << " with std::map: " << elapsed * 1000 << "ms" << std::endl;

    return 0;
}
