
#include "../includes/PhoneBook.class.hpp"

std::string PhoneBook::ft_cut(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 10) + "...");
    return (str);
}

void    PhoneBook::ft_search(void)
{
    if (contact_nb == 0)
        return (std::cout << "No contact exists. Use ADD command." << std::endl, (void)0);
    ft_show();
    
}

void    PhoneBook::ft_show(void)
{
    std::string     tmp;

    std::cout << "--------------------------------------------------" << std::endl;
    for (int i = 0 ; i < contact_nb ; i++)
    {
        tmp = "Nick name      : ";
        std::cout << tmp.append(contact[i].GetElement(4)) << std::endl;
        tmp = "Last name      : ";
        std::cout << tmp.append(contact[i].GetElement(3)) << std::endl;
        tmp = "First name     : ";
        std::cout << tmp.append(contact[i].GetElement(2)) << std::endl;
        tmp = "Phone number   : ";
        std::cout << tmp.append(contact[i].GetElement(1)) << std::endl;
        tmp = "Darkest secret : ";
        std::cout << tmp.append(contact[i].GetElement(0)) << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
    }
}

void    PhoneBook::ft_add(void)
{
    std::string input;

    std::cout << "First name: ";
    ft_getline(input, false);
    contact[contact_index].SetElement(input, 2);

    std::cout << "Last name: ";
    ft_getline(input, false);
    contact[contact_index].SetElement(input, 3);

    std::cout << "Nick name: ";
    ft_getline(input, false);
    contact[contact_index].SetElement(input, 4);

    std::cout << "Phone number: ";
    ft_getline(input, false);
    contact[contact_index].SetElement(input, 1);

    std::cout << "Darkest secret: ";
    ft_getline(input, false);
    contact[contact_index].SetElement(input, 0);

    contact_index++;
    if (contact_index == 8)
        contact_index = 0;
    if (contact_nb < 8)
        contact_nb++;
}
