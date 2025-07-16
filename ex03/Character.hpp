#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];
public:
    Character();
    Character(const std::string& input);
    Character(const Character& other);
    Character& operator=(const Character& const);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
