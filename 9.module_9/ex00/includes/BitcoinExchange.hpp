#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <string>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

class BitcoinExchange
{
	public:
		BitcoinExchange(const char *request);
		~BitcoinExchange(void);

		void									setDatabase(char *src);
		void									setDatabase(const char *src);
		std::map<std::string, std::string>		getDatabase(void);
		std::map<std::string, std::string>		getRequest(void);
		void									getValues(void);

		class OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidHeaderException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class WrongExtensionException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::map<std::string, std::string>		_database;
		std::map<std::string, std::string>		_request;

		bool	isValid(std::map<std::string, std::string>::iterator it, \
		std::map<std::string, std::string>::iterator it2);
};

std::pair<std::string, std::string>		getNextLineAndSplitIntoTokens(std::istream& str, const char separator);
bool									parse(std::map<std::string, std::string> &line);
bool									isValidDate(std::string dateStr);
std::map<std::string, std::string>		parseDatabase(const char *argv);
std::map<std::string, std::string>		parseRequest(const char *argv);
bool									isNumeric(std::string str);
std::map<std::string, std::string>		parseDatabase(char *argv);

#endif
