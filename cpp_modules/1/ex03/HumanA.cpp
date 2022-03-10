#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( const std::string &name, Weapon &weapon )
{
	this->name = name;
	this->weapon = weapon;
}
