#include <iostream>
#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat kkaneko("kkaneko", 150);

	std::cout << kkaneko << std::endl;
	kkaneko.Promote();
	std::cout << kkaneko << std::endl;
	kkaneko.Demote();
	std::cout << kkaneko << std::endl;
	kkaneko.Demote();
	return (0);
}
