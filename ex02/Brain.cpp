#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Default brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for(int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& content)
{
    if (index < 100 && index >= 0)
        ideas[index] = content;
    else
        std::cerr << "Index is out of range, select from 0-99" << std::endl;
}

const std::string& Brain::getIdea(int index) const
{
    if (index < 100 && index >= 0)
        return (ideas[index]);
    else
    {
        std::cerr << "Index is out of range, select from 0-99" << std::endl;
        static const std::string empty = "";
        return empty;
    }
}