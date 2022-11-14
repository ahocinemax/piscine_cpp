#include "../includes/Zombie.Class.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie has been created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie has been destroyed" << std::endl;;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...";
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
