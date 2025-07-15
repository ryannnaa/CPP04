#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    {
        Animal *array[4];

        for (int i = 0; i < 4; i++)
        {
            if (i <= 1)
                array[i] = new Cat();
            else
                array[i] = new Dog();
        }
        for (int i = 0; i < 4; i ++)
        {
            array[i]->makeSound();
        }
        for (int i = 0; i < 4; i++)
            delete array[i];
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

        std::cout << "[ Testing out of bound index ]\n";
        std::cout << "Original's idea[-1]: " << original.getIdea(-1) << std::endl;
        std::cout << "Copy's idea[100]: " << copy.getIdea(100) << std::endl;
    }
    return 0;
}