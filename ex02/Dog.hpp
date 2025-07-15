#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
private:
    Brain *brain;
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    void setIdea(int index, const std::string& content);
    const std::string& getIdea(int index) const;
    const std::string& getType() const;
    void makeSound() const;
};

#endif