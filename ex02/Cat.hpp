#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
private:
    Brain *brain;
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void setIdea(int index, const std::string& content);
    const std::string& getIdea(int index) const;
    const std::string& getType() const;
    void makeSound() const;
};

#endif