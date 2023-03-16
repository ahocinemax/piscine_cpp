#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange(const char *request);
		~BitcoinExchange(void);
		BitcoinExchange(void);

		void  setDatabase(char *src);
		void  setDatabase(const char *src);
		std::vector<std::vector<std::string> >  getDatabase(void);
		void  getValues(void);
		std::vector<std::string> 				_getNextLineAndSplitIntoTokens(std::istream& str);

		class TooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: too large a number.";
				}
		};

		class NegativeException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: Not a positive number.";
				}
		};

		class InvalidInputException : public std::exception
		{
			private:
				std::string _src;
			public:
				InvalidInputException(void);
				InvalidInputException(std::string &src) : _src(src) {}
				~InvalidInputException(void) throw() {}
				virtual const char *what() const throw()
				{
					std::string msg = "Error: bad input => ";
					return (msg.append(_src).c_str());
				}
		};

		class OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: Could not open file.";
				}
		};

	private:
		std::vector<std::vector<std::string> >  _database;
		std::vector<std::vector<std::string> >  _request;

		std::vector<std::vector<std::string> >	_parseDatabase(char *argv);

};

#endif
