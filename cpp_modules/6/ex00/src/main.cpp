#include <iostream>

static void print_usage(void);

int main( int ac, char **av )
{
	if (ac != 2)
	{
		print_usage();
		return (1);
	}

	
	return (0);
}

static void print_usage(void)
{
	std::cout << "usage: ./convert <literal to convert>" << std::endl;
}
