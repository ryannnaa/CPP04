#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure()
    : AMateria("cure")
{}

Cure::Cure(const Cure& other)
    : AMateria(other.getType())
{}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        this->type = other.getType();
    }
    return (*this);
}

Cure::~Cure()
{}

Cure* Cure::clone() const
{
    std::cout << "Cloning Cure Materia" << std::endl;
    Cure *clone = new Cure();
    return (clone);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
