#include "ICharacter.hpp"
#include <iostream>

ICharacter::~ICharacter()
{
    std::cout << "Character Interface destroyed" << std::endl;
}