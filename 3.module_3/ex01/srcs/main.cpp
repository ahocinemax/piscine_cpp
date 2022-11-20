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
	
	assert(scavTrap.getHitPoints() == 100);
	assert(scavTrap.getEnergyPoints() == 49);

	scavTrap.takeDamage(5);

	assert(scavTrap.getHitPoints() == 95);
	assert(scavTrap.getEnergyPoints() == 49);

	scavTrap.beRepaired(5);

	assert(scavTrap.getHitPoints() == 100);
	assert(scavTrap.getEnergyPoints() == 48);

	scavTrap.guardGate();

	scavTrap.takeDamage(100);
	assert(scavTrap.getHitPoints() == 0);

	// ScavTrap is dead now, can't do anything

	return (0);
}