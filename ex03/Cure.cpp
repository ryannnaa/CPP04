#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure()
    : AMateria("cure")
{
    std::cout << "Cure Materia constructed" << std::endl;
}

Cure::Cure(const Cure& other)
    : AMateria(other.getType())
{
    std::cout << "Cure Materia copied" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << "Cure Materia assigned" << std::endl;
    if (this != &other)
    {
        this->type = other.getType();
    }
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure Materia destroyed" << std::endl;
}

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
