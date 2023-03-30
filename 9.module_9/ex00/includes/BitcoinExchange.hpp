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
		std::vector<std::vector<std::string> >  getRequest(void);
		void									getValues(void);

		class OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::vector<std::vector<std::string> >  _database;
		std::vector<std::vector<std::string> >  _request;

};

std::vector<std::string>				getNextLineAndSplitIntoTokens(std::istream& str, const char separator);
bool									parse(std::vector<std::string> &line);
bool									isValidDate(std::string dateStr);
std::vector<std::vector<std::string> >	parseDatabase(const char *argv);
std::vector<std::vector<std::string> >	parseRequest(const char *argv);
bool									isNumeric(std::string str);
std::vector<std::vector<std::string> >	parseDatabase(char *argv);
bool	isValid(std::vector<std::vector<std::string> >::iterator it, \
std::vector<std::vector<std::string> >::iterator it2);

#endif
