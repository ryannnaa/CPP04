#include "Character.hpp"
#include <iostream>

Character::Character()
	: name("Default")
{
    std::cout << "Default Character created" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = nullptr;
}

Character::Character(const std::string& input)
	: name(input)
{
    std::cout << "Character created" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = nullptr;
}

Character::Character(const Character& other)
	: name(other.name)
{
    std::cout << "Creating copy of " << other.getName() << std::endl;
   for (int i; i < 4; i++)
   {
	  if (other.inventory[i])
	  	this->inventory[i] = other.inventory->clone();
	  else
		this->inventory[i] = nullptr;
   } 
}

Character& Character::operator=(const Character& other)
{
    std::cout << "Assigning copy of " << other.getName() << std::endl;
    if (this != &other)
    {
	for (int i; i < 4; i++)
	{
		delete inventory[i];
		inventory[i] = nullptr;
	}
        this->name = other.getName();
        for (int i; i < 4; i++)
        {
	    if (other.inventory[i])
		    this->inventory[i] = other.inventory->clone();
	    else
		    this->inventory[i] = nullptr;
        }
    }
}

Character::~Character()
{
	std::cout << "Character destroyed" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			inventory[i] = nullptr;
		}
	}
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == nullptr)
		{
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (inventory[idx] != nullptr)
			inventory[idx]->use(target);
	}
}

			
