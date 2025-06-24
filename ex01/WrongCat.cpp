#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    std::cout << "Default WrongCat constructor called" << std::endl;
    brain = new Brain();
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
    delete brain;
}

void WrongCat::setIdea(int index, const std::string& content)
{
    brain->setIdea(index, content);
}

const std::string& WrongCat::getIdea(int index) const
{
    return (brain->getIdea(index));
}

void WrongCat::makeSound() const
{
    std::cout <<"meow.. meow" << std::endl;
}
