#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <exception>
# include <stdlib.h>

class RPN
{
	public:
		RPN();
		RPN(RPN const & src);
		~RPN();

		RPN & operator=(RPN const & rhs);

		void		push_tokens(std::string const & str);
		void		push_digits(std::string const & str);
		void		pop();
		void		add();
		void		sub();
		void		mul();
		void		div();
		void		print();
		void		calculate();
		void		_exit(int code);
		const std::stringstream	&getSs() const;

	private:
		std::stack<char>	_tokens;
		std::stack<int>		_stack;
		std::stringstream	_ss;
};

#endif