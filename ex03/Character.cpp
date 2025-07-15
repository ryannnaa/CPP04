#include "Character.hpp"

Character::Character()
    : name("Default")
{}

Character::Character(const std::string& input)
    : name(input)
{}

Character::Character(const Character& other)
{}

Character& Character::operator=(const Character& const)
{}

Character::~Character()
{}

std::string const & Character::getName() const
{
    return (this->name);
}