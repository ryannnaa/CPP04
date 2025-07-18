#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice()
    : AMateria("ice")
{}

Ice::Ice(const Ice& other)
    : AMateria(other.getType())
{}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        this->type = other.getType();
    }
    return (*this);
}

Ice::~Ice()
{}

Ice* Ice::clone() const
{
    std::cout << "Cloning Ice Materia" << std::endl;
    Ice *clone = new Ice();
    return (clone);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
