#include "Animal.hpp"
#include <iostream>

Animal::Animal()
    : type("Undefined")
{}

Animal::Animal(std::string type)
    : type(type)
{}

Animal::Animal(const Animal& other)
    : type(other.type)
{}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{}

const std::string& Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const
{
    std::cout << "*inaudible noises*" << std::endl;
}