#include <string>
#include <iostream>

int main(void)
{
    std::string name = "HI THIS IS BRAIN";
    std::string *stringPTR = &name;
    std::string &stringREF = name;

    std::cout << "Address of name       : " << &name << std::endl;
    std::cout << "Address of stringREF  : " << &stringREF << std::endl;
    std::cout << "Address of stringPTR  : " << &stringPTR << std::endl;

    std::cout << std::endl;

    std::cout << "Value of name         : " << name << std::endl;
    std::cout << "Value of stringREF    : " << stringREF << std::endl;
    std::cout << "Value of stringPTR    : " << *stringPTR << std::endl;
}
