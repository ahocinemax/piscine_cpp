#ifndef MUTANTSTACK_CLASS_HPP
# define MUTANTSTACK_CLASS_HPP

# include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(void) : MutantStack<T, Container>::stack() {};
		MutantStack(const MutantStack<T, Container> &Copy) : MutantStack<T, Container>::stack(Copy) {};
		~MutantStack(void) {};
		MutantStack &operator=(const MutantStack<T, Container> &rhs)
		{
			if (this != &rhs)
				this->MutantStack<T, Container>::stack::operator=(rhs);
			return (*this);
		}
		typedef typename Container::reverse_iterator	reverse_iterator;
		typedef typename Container::iterator			iterator;

		reverse_iterator	rbegin() {return this->c.rbegin();};
		reverse_iterator	rend() {return this->c.rend();};
		iterator	begin() {return this->c.begin();};
		iterator	end() {return this->c.end();};
};

#endif