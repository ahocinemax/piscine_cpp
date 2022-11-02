#ifndef
# define ZOMBIE_CLASS_HPP

<class Zombie
{
private:
	std::string		_name;
public:
	Zombie(/* args */);
	~Zombie();
	void	announce(void);
	*Zombie	newZombie(std::string _name);
	void	randomChump( std::string name );
};

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
}


#endif