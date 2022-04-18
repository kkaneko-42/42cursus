#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <class T>
T &easyfind(T &container, int n)
{
	const T::const_iterator kItEnd = container.end();
	T::const_iterator it = container.begin();

	while (*it != kItEnd && *it != n)
		++it;
	return (it);
}

#endif //EASYFIND_HPP
