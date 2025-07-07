#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    {
        const WrongAnimal* k = new WrongCat();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << std::endl << "[ Animals? ]" << std::endl;
        std::cout << k->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        std::cout << std::endl << "[ Sounds? ]" << std::endl;
        k->makeSound();
        j->makeSound();
        i->makeSound(); //will output the cat sound!
        std::cout << std::endl;

        delete k;
        delete j;
        delete i;
    }
    {
        std::cout << std::endl << "[ Testing deep copy with Cat ]\n";

        Cat original;
        original.setIdea(0, "Original idea");
    
        Cat copy(original); // invokes copy constructor
    
        std::cout << "Original's idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "Copy's idea[0]: " << copy.getIdea(0) << std::endl;
    
        // Modify the original's idea
        original.setIdea(0, "Changed idea");
    
        std::cout << "After changing original:\n";
        std::cout << "Original's idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "Copy's idea[0]: " << copy.getIdea(0) << std::endl << std::endl;
    }
    return 0;
}