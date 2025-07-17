#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructed" << std::endl;

	for (int i = 0; i < 4; i++)
		this->memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "Copy of MateriaSource created" << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i])
		{
			delete this->memory[i];
			this->memory[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i])
			this->memory[i] = other.memory[i]->clone();
		else
			this->memory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource assigned" << std::endl;

	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->memory[i])
			{
				delete this->memory[i];
				this->memory[i] = other.memory[i]->clone();
			}
			else
				this->memory[i] = other.memory[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destroyed" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i])
		{
			delete this->memory[i];
			this->memory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *source)
{
	std::cout << "Learning Materia" << std::endl;
	
	if (source)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->memory[i] == NULL)
			{
				this->memory[i] = source->clone();
				break;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &input)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i])
		{
			if (this->memory[i]->getType() == input)
				return (this->memory[i]->clone());
		}
	}
	return (NULL);
}
