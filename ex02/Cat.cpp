#include "Cat.hpp"
#include <iostream>

Cat::Cat()
    : Animal("Cat")
{
    std::cout << "Default cat constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat& other)
    : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::setIdea(int index, const std::string& content)
{
    brain->setIdea(index, content);
}

const std::string& Cat::getIdea(int index) const
{
    return (brain->getIdea(index));
}

void Cat::makeSound() const
{
    std::cout <<"meow.. meow" << std::endl;
}

const std::string& Cat::getType() const
{
    return (this->type);
}