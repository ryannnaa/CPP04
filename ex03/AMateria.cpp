#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
    : element("Default")
{
    std::cout << "Default Materia constructed" << std::endl;
}

AMateria::AMateria(std::string const & type)
    : element(type)
{
    std::cout << type << " Materia constructed" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "Materia copied" << std::endl;
    element = other.getType();
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "Materia assigned" << std::endl;
    if (this != &other)
    {
        element = other.getType();
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "Materia destroyed" << std::endl;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Does something to " << target.getName() << std::endl;
} 
