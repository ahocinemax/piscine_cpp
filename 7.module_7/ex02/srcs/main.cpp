#include <iostream>
#include "../includes/Array.Class.hpp"
#include <stdlib.h>

#define MAX_VAL 50
int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    try
    {
        for (int i = 0; i < MAX_VAL - 1 ; i++)
        {
            int value = rand();
            std::cout << i << " <- i || value -> " << value << std::endl;
            numbers[i] = value;
            mirror[i] = value;
        }

        Array<int> tmp = numbers;
        Array<int> test(tmp);

        numbers[-2] = 0;
        numbers[MAX_VAL] = 0;

        for (int i = 0; i < MAX_VAL - 1 ; i++)
        {
            numbers[i] = rand();
        }

    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    delete [] mirror;//
    return 0;
}

