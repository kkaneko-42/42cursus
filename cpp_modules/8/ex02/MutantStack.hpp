#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

class MutantStack
{
	public:
		MutantStack( void );
		MutantStack( const MutantStack &src );
		virtual ~MutantStack( void );

		MutantStack &operator =( const MutantStack &rhs );
};

#endif //MUTANTSTACK_HPP
