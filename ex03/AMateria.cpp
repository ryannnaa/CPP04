#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria()
    : type("Default")
{}

AMateria::AMateria(std::string const & type)
    : type(type)
{}

AMateria::AMateria(const AMateria& other)
{
    type = other.getType();
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        type = other.getType();
    }
    return (*this);
}

AMateria::~AMateria()
{}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Does something to " << target.getName() << std::endl;
} 
