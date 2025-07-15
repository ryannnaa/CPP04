#include "Dog.hpp"
#include <iostream>

Dog::Dog()
    : Animal("Dog")
{
    std::cout << "Default dog constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog& other)
    : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::setIdea(int index, const std::string& content)
{
    brain->setIdea(index, content);
}

const std::string& Dog::getIdea(int index) const
{
    return (brain->getIdea(index));
}

void Dog::makeSound() const
{
    std::cout <<"woof.. woof" << std::endl;
}

const std::string& Dog::getType() const
{
    return (this->type);
}