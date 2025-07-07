#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const WrongAnimal* k = new WrongCat();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl << "[ Animals? ]" << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl << "[ Sounds? ]" << std::endl;
    meta->makeSound();
    k->makeSound();
    j->makeSound();
    i->makeSound(); //will output the cat sound!
    std::cout << std::endl;

    delete meta;
    delete k;
    delete j;
    delete i;

    return 0;
}