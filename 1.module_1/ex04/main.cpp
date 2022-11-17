/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:04:13 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/17 00:05:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <string>

int	main(int argc, char *argv[])
{
	std::string		filename(argv[1]);
	std::string		newLine = filename + ".replace";
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	size_t			index = 0;
	std::ofstream	outfile;
	std::fstream	infile;

	if (argc != 4)
	{
		std::cout << "Sed: usage: ./Sed [FILE] [S1] [S2]" << std::endl;
		return (1);
	}

	infile.open(filename.c_str(), std::fstream::in);
	if (infile.fail())
	{
		std::cout << "Sed: file: Error. Counld not open file." << std::endl;
		return (2);
	}

	outfile.open(newLine.c_str(), std::ios::out);
	if (outfile.fail())
	{
		std::cout << "Sed: file: Error. Could not create file." << std::endl;
		return (3);
	}

	if (s1.empty())
	{
		std::cout << "S1 cannot be empty." << std::endl;
		return (4);
	}

	while (getline(infile, newLine))
	{
		index = 0;
		while ((index = newLine.find(s1, index)) != s1.npos)
		{
			newLine.erase(index, s1.length());
			newLine.insert(index, s2);
			index += s2.length();
		}
		outfile << newLine;
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}