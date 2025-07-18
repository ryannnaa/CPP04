#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
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
	if (source)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->memory[i] == NULL)
			{
				this->memory[i] = source->clone();
				std::cout << "Learning Materia" << std::endl;
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
