
#include "../includes/PhoneBook.class.hpp"

std::string PhoneBook::ft_cut(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 10) + "...");
    return (str);
}

int PhoneBook::ft_check_input(std::string input)
{
    return (input == "0" || input == "1" || input == "2" || input == "3" || \
    input == "4" || input == "5" || input == "6" || input == "7");
}

void    PhoneBook::ft_search(void)
{
    std::string input;
    int         index = -1;

    if (contact_nb == 0)
        return (std::cout << "\e[33mNo contact exists. Use ADD command. \e[0m" \
        << std::endl, (void)0);
    ft_show();
    while (index < 0)
    {
        ft_getline(input, "Choose an index between 0 - 7 : ", false);
        std::istringstream(input) >> index;
        if (index > contact_nb - 1 || index < 0 || !ft_check_input(input))
        {
            std::cout << "This contact does not exist." << std::endl;
            index = -1;
        }
    }
    contact[index].show();
}

void    PhoneBook::ft_show(void)
{
    std::string     tmp;

    std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Index          ";
    std::cout << "| First name     ";
    std::cout << "| Last name      ";
    std::cout << "| Nick name      ";
    std::cout << "| Phone number   ";
    std::cout << "| Darkest secret |";
    std::cout << std::endl;
    std::cout << "|_____________________________________________________________________________________________________|" << std::endl;
    for (int i = 0 ; i < contact_nb ; i++)
    {
        std::cout << "| ";
        std::cout << std::left << std::setw(15) << i << "| ";
        std::cout << std::left << std::setw(15) << ft_cut(contact[i].GetElement(2)) << "| ";
        std::cout << std::left << std::setw(15) << ft_cut(contact[i].GetElement(3)) << "| ";
        std::cout << std::left << std::setw(15) << ft_cut(contact[i].GetElement(4)) << "| ";
        std::cout << std::left << std::setw(15) << ft_cut(contact[i].GetElement(1)) << "| ";
        std::cout << std::left << std::setw(15) << ft_cut(contact[i].GetElement(0)) << "| ";
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
}

void    PhoneBook::ft_add(void)
{
    std::string input;

    ft_getline(input, "First name: ", false);
    contact[contact_index].SetElement(input, 2);

    ft_getline(input, "Last name: ", false);
    contact[contact_index].SetElement(input, 3);

    ft_getline(input, "Nick name: ", false);
    contact[contact_index].SetElement(input, 4);

    ft_getline(input, "Phone number: ", false);
    contact[contact_index].SetElement(input, 1);

    ft_getline(input, "Darkest secret: ", false);
    contact[contact_index].SetElement(input, 0);

    contact_index++;
    if (contact_index == 8)
        contact_index = 0;
    if (contact_nb < 8)
        contact_nb++;
}
