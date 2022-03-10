#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->setType(type);
}

const std::string &Weapon::getType( void )
{
	return (this->type);
}

void Weapon::setType( std::string type )
{
	this->type = type;
}
