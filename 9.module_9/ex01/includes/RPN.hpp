#ifndef RNP_HPP
# define RNP_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <exception>
# include <stdlib.h>

enum e_tokens
{
	SUM,
	SUB,
	MUL,
	DIV,
};


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
		void		dump();
		void		assert(std::string const & str);
		void		add();
		void		sub();
		void		mul();
		void		div();
		void		print();
		void		calculate();
		void		_exit(int code);
		const std::stringstream &getSs() const { return (this->_ss); }

	private:
		std::stack<char>	_tokens;
		std::stack<int>		_stack;
		std::stringstream	_ss;
};

#endif