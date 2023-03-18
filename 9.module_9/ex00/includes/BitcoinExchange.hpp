#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <string>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

class BitcoinExchange
{
	public:
		BitcoinExchange(const char *request);
		~BitcoinExchange(void);

		void  									setDatabase(char *src);
		void  									setDatabase(const char *src);
		std::vector<std::vector<std::string> >  getDatabase(void);
		void									getValues(void);

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

};

std::vector<std::string>				getNextLineAndSplitIntoTokens(std::istream& str);
bool									parse(std::vector<std::string> &line);
bool									isValidDate(std::string dateStr);
std::vector<std::vector<std::string> >	parseDatabase(const char *argv);
bool									isNumeric(std::string str);
std::vector<std::vector<std::string> >	parseDatabase(char *argv);

#endif
