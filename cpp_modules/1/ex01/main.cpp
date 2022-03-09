#include <iostream>
#include <string>
#include "Zombie.hpp"

int main( int ac, char **av)
{
	(void)ac;
	const int nb_zombies = 10;
	std::string input(av[1]);
	Zombie *res = zombieHorde(nb_zombies, input);

	std::cout << "-----check all zombie-----" << std::endl;
	for (int i = 0; i < nb_zombies; ++i)
	{
		std::cout << "No." << i << std::endl;
		res[i].announce();
	}

	std::cout << "----free zombies-----" << std::endl;
	delete[] res;

	return (0);
}
