#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"



//int main()
//{
//    IMateriaSource* src = new MateriaSource();
//    AMateria* ice = new Ice();
//    AMateria* cure = new Cure();
//    src->learnMateria(ice);
//    src->learnMateria(cure);
//    
//    ICharacter* me = new Character("me");
//
//    AMateria* tmp;
//    tmp = src->createMateria("ice");
//    me->equip(tmp);
//    tmp = src->createMateria("cure");
//    me->equip(tmp);
//
//    ICharacter* bob = new Character("bob");
//    
//    me->use(0, *bob);
//    me->use(1, *bob);
//
//    delete bob;
//    delete me;
//    delete ice;
//    delete cure;
//    delete src;
//
//    return 0;
//}

int main ()
{
	IMateriaSource* src = new MateriaSource();
	AMateria *array[5];
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			array[i] = new Ice();
		else
			array[i] = new Cure();
	}

	for (int i = 0; i < 5; i++)
		src->learnMateria(array[i]);

	ICharacter* me = new Character("me");

	AMateria* tmp;
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			tmp = src->createMateria("ice");
		else
			tmp = src->createMateria("cure");
		me->equip(tmp);
	}
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter* you = new Character("you");

	me->use(0, *you);
	me->use(1, *you);
	me->use(5, *you);

	delete you;
	delete me;
	for (int i = 0; i < 5; i++)
		delete array[i];
	delete src;
	delete tmp;

	return (0);
}
