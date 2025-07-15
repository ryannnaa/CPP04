#include "Ice.hpp"
#include <iostream>

Ice::Ice()
    : AMateria("ice")
{
    std::cout << "Ice Materia constructed" << std::endl;
}

Ice::Ice(const Ice& other)
    : AMateria(other.getType())
{
    std::cout << "Ice Materia copied" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << "Ice Materia assigned" << std::endl;
    if (this != &other)
    {
        this->element = other.getType();
    }
}

Ice::~Ice()
{
    std::cout << "Ice Materia destroyed" << std::endl;
}

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