#include "Character.hpp"
#include <iostream>

Character::Character()
	: name("Default")
{
    std::cout << "Default Character created" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const std::string& input)
	: name(input)
{
    std::cout << "Character created" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character& other)
	: name(other.name)
{
    std::cout << "Creating copy of " << other.getName() << std::endl;
   for (int i = 0; i < 4; i++)
   {
	  if (other.inventory[i])
	  	this->inventory[i] = other.inventory[i]->clone();
	  else
		this->inventory[i] = NULL;
   } 
}

Character& Character::operator=(const Character& other)
{
    std::cout << "Assigning copy of " << other.getName() << std::endl;
    if (this != &other)
    {
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
	}
        this->name = other.getName();
        for (int i = 0; i < 4; i++)
        {
	    if (other.inventory[i])
		    this->inventory[i] = other.inventory[i]->clone();
	    else
		    this->inventory[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
	std::cout << "Character destroyed" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			inventory[i] = NULL;
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
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (inventory[idx] != NULL)
			inventory[idx]->use(target);
	}
}

			
