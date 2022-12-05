#include "../includes/ScavTrap.Class.hpp"

int main()
{
	ScavTrap scavTrap("scavTrapy");

	std::cout << "------------------" << std::endl;
	std::cout << "initial stats:" << std::endl;
	std::cout << "hit points: " << scavTrap.getHitPoints() << std::endl;
	std::cout << "energy points: " << scavTrap.getEnergyPoints() << std::endl;
	std::cout << "attack damage: " << scavTrap.getAttackDamage() << std::endl;
	std::cout << "------------------" << std::endl;

	scavTrap.attack("enemy");
	
	scavTrap.takeDamage(5);

	scavTrap.beRepaired(5);

	scavTrap.guardGate();

	scavTrap.takeDamage(100);
	// ScavTrap is dead now, can't do anything

	return (0);
}