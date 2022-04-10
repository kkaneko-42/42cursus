#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

void DefaultTest( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// const AAnimal* k = new AAnimal();

	delete j;//should not create a leak
	delete i;
}

// void MyTest( void )
// {
// 	const size_t kArrayLen = 10;
// 	Animal *animals = new Animal[kArrayLen];
// 	Dog dogs[kArrayLen / 2];
// 	Cat cats[kArrayLen / 2];
// 	size_t i = 0;
// 	size_t j = 0;

// 	while (i < kArrayLen / 2)
// 	{
// 		animals[i] = dogs[i];
// 		++i;
// 	}
// 	while (i < kArrayLen)
// 	{
// 		animals[i] = cats[j];
// 		++i;
// 		++j;
// 	}

// 	delete[] animals;
// }

int main()
{
	DefaultTest();
	return 0;
}
