#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

class	MateriaSource
{
private:
	AMateria *memory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void learnMateria(AMateria *source);
	MateriaSource& createMateria(std::string const &input);
};

#endif
