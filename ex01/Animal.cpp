#include "Animal.hpp"
#include <iostream>

Animal::Animal()
    : type("Undefined")
{
    std::cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
    : type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
    : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

const std::string& Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const
{
    std::cout << "*inaudible noises*" << std::endl;
}