#include "../includes/Data.Class.hpp"

int main(void)
{
	uintptr_t uint = 0;
	
	{
		Data *ptr = new Data;

		std::cout << "\033[034m" << "char ptr value  :" << ptr->getVal() << "\033[0m" << std::endl;
		std::cout << "\033[034m" << "address value   :" << &ptr << "\033[0m" << std::endl;
		uint = serialize(ptr);
		std::cout << "\033[032m" << "uintptr_t value :" << uint << "\033[0m" << std::endl;
		ptr = deserialize(uint);
		std::cout << "\033[035m" << "char ptr value  :" << ptr->getVal() << "\033[0m" << std::endl;
		std::cout << "\033[035m" << "address value   :" << &ptr << "\033[0m" << std::endl;
		delete ptr;
	}
	
	std::cout << std::endl;
	Data *tst = new Data('x');
	uint = 0;
	
	std::cout << "\033[034m" << "char ptr value  :" << tst->getVal() << "\033[0m" << std::endl;
	std::cout << "\033[034m" << "address value   :" << &tst << "\033[0m" << std::endl;
	uint = serialize(tst);
	std::cout << "\033[032m" << "uintptr_t value :" << uint << "\033[0m" << std::endl;
	tst = deserialize(uint);
	std::cout << "\033[035m" << "char ptr value  :" << tst->getVal() << "\033[0m" << std::endl;
	std::cout << "\033[035m" << "address value   :" << &tst << "\033[0m" << std::endl;
	
	delete tst;
	return (0);
}