#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <exception>
# include <vector>

class Span
{
	private:
		std::vector<int>	tab;
		unsigned int		size;

	public:
		Span(const unsigned int &nb);
		Span(const Span &Copy);

		Span &operator=(const Span &rhs);

		~Span(void);

		unsigned int	getSize(void) const;

		void 	addNumber(int nb);
		void	addNumber(const std::vector<int>::iterator &start, const std::vector<int>::iterator &end);

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		class EmptyArrayException : public std::exception
		{
			public:
				virtual const char	*what() const throw() {return ("Array is empty\n");}
		};

		class ArrayFullException : public std::exception
		{
			public:
				virtual const char	*what() const throw() {return ("Array is full\n");}
		};
};

#endif