#include "Dog.hpp"
#include <iostream>

Dog::Dog()
    : Animal("Dog")
{}

Dog::Dog(const Dog& other)
    : Animal(other)
{}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return (*this);
}

Dog::~Dog()
{}

void Dog::makeSound() const
{
    std::cout <<"woof.. woof" << std::endl;
}