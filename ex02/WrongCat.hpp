#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
private:
    Brain *brain;
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();

    void setIdea(int index, const std::string& content);
    const std::string& getIdea(int index) const;
    void makeSound() const;
};

#endif