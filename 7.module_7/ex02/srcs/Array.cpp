#include "../includes/Array.Class.hpp"
template class Array<int>;
template class Array<std::string>;

Array::Array(void) : size(0), array(new T[0])
{
    ;
}

Array::Array(size_t n) : size(n), array(new T[n]) 
{
    ;
}

Array::Array(const Array &Copy)
{
    this->size = Copy->size;
    this->array = new T[Copy->size];
    for (size_t i = 0 ; i < Copy->size ; i++)
        this->array[i] = Copy.array[i];
}

Array::~Array(void)
{
    delete [] this->array;
}

Array::Array &operator=(const Array &rhs)