#ifndef DATA_CLASS_HPP
# define DATA_CLASS_HPP

# include <string>
# include <iostream>

class Data
{
private:
	char val;

public:
	Data &operator=(const Data &Copy);
	Data(char c);
	Data(const Data &Copy);
	Data(void);
	~Data(void);

	const char	&getVal(void) const;
};

Data		*deserialize(uintptr_t raw);
uintptr_t	serialize(Data* ptr);

#endif