#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout <<"meow.. meow" << std::endl;
}