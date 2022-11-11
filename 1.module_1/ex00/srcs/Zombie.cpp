#include "../includes/Zombie.Class.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie \"" << this->name << "\" has been created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie \"" << this->name << "\" has been destroyed" << std::endl;;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...";
}

Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}

void	randomChump(std::string name)
{
	Zombie	zombie = Zombie(name);
	zombie.announce();
	std::cout << std::endl;
}
