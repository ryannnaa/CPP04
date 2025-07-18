#include "Character.hpp"
#include <iostream>

Character::Character()
	: name("Default")
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const std::string& input)
	: name(input)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character& other)
	: name(other.name)
{
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
			std::cout << "Materia equipped" << std::endl;
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

			
