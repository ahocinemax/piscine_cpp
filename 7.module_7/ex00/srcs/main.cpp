#include "../includes/Whatever.Class.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "--------------- string swap ---------------" << std::endl;
	std::string strA = "chaine1";
	std::string strB = "chaine2";

	std::cout << "'a': " << strA << std::endl;
	std::cout << "'b': " << strB << std::endl;
	std::cout << "\n";
	::swap(strA, strB);
	std::cout << "'a': " << strA << ", 'b': " << strB << std::endl;
	std::cout << "min(a,b) = " << ::min(strA, strB) << std::endl;
	std::cout << "max(a,b) = " << ::max(strA, strB) << std::endl;

	std::cout << "--------------- float swap ---------------" << std::endl;

	float floatA = 3.5;
	float floatB = 2.9;

	std::cout << "'a': " << floatA << std::endl;
	std::cout << "'b': " << floatB << std::endl;
	std::cout << "\n";
	::swap(floatA, floatB);
	std::cout << "'a': " << floatA << ", 'b': " << floatB << std::endl;
	std::cout << "min(a,b) = " << ::min(floatA, floatB) << std::endl;
	std::cout << "max(a,b) = " << ::max(floatA, floatB) << std::endl;

	std::cout << "--------------- double swap ---------------" << std::endl;

	double doubleA = 2000.452;
	double doubleB = -124.0;

	std::cout << "'a': " << doubleA << std::endl;
	std::cout << "'b': " << doubleB << std::endl;
	std::cout << "\n";
	::swap(doubleA, doubleB);
	std::cout << "'a': " << doubleA << ", 'b': " << doubleB << std::endl;
	std::cout << "min(a,b) = " << ::min(doubleA, doubleB) << std::endl;
	std::cout << "max(a,b) = " << ::max(doubleA, doubleB) << std::endl;

	return (0);
}