#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string		name;
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif