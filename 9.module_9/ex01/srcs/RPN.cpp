#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const & src) { *this = src; }
RPN::~RPN() {}

RPN & RPN::operator=(RPN const & rhs)
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
		this->_ss.str(rhs._ss.str());
	}
	return (*this);
}

void	RPN::push_tokens(std::string const & str)
{
	this->_ss << str;
	char	n;
	this->_ss >> n;
	this->_tokens.push(n);
	this->_ss.clear();
}

void	RPN::push_digits(std::string const & str)
{
	this->_ss << str;
	int		n;
	this->_ss >> n;
	this->_stack.push(n);
	this->_ss.clear();
}

void	RPN::pop()
{
	if (this->_stack.empty())
		throw std::exception();
	this->_stack.pop();
}

void	RPN::add()
{
	if (this->_stack.size() < 2)
		return ;
	int		n1 = this->_stack.top();
	this->_stack.pop();
	int		n2 = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(n1 + n2);
}

void	RPN::sub()
{
	if (this->_stack.size() < 2)
		throw std::exception();
	int		n1 = this->_stack.top();
	this->_stack.pop();
	int		n2 = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(n1 - n2);
}

void	RPN::mul()
{
	if (this->_stack.size() < 2)
		throw std::exception();
	int		n1 = this->_stack.top();
	this->_stack.pop();
	int		n2 = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(n1 * n2);
}

void	RPN::div()
{
	if (this->_stack.size() < 2)
		throw std::exception();
	int		n1 = this->_stack.top();
	this->_stack.pop();
	int		n2 = this->_stack.top();
	this->_stack.pop();
	if (n2 == 0)
		throw std::exception();
	this->_stack.push(n1 / n2);
}

void	RPN::print()
{
	if (this->_stack.empty())
		throw std::exception();
	std::cout << static_cast<char>(this->_stack.top()) << std::endl;
}

void	RPN::calculate()
{
	// Check if there is enough tokens and digits
	if (this->_stack.empty())
		throw std::exception();
	// Check for the right number of tokens according to the number of digits
	if (this->_tokens.size() != this->_stack.size() - 1)
		throw std::exception();
	while (!this->_tokens.empty())
	{
		switch (this->_tokens.top())
		{
			case '+':
				this->add();
				break;
			case '-':
				this->sub();
				break;
			case '*':
				this->mul();
				break;
			case '/':
				this->div();
				break;
			default:
				throw std::exception();
		}
		this->_tokens.pop();
	}
	std::cout << this->_stack.top() << std::endl;
}

void	RPN::_exit(int code) { exit(code); }
