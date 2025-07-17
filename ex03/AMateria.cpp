#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria()
    : type("Default")
{
    std::cout << "Default Materia constructed" << std::endl;
}

AMateria::AMateria(std::string const & type)
    : type(type)
{
    std::cout << type << " Materia constructed" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "Materia copied" << std::endl;
    type = other.getType();
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "Materia assigned" << std::endl;
    if (this != &other)
    {
        type = other.getType();
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "Materia destroyed" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Does something to " << target.getName() << std::endl;
} 
