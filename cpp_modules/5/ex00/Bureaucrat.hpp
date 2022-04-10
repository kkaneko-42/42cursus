#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	class GradeException : public std::exception
	{
		public:
			std::string const &what( void );
		private:
			std::string msg;
	};

	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &src );
		Bureaucrat( const std::string &name );
		Bureaucrat( const int grade );
		Bureaucrat( const std::string &name, const int grade );
		virtual ~Bureaucrat( void );

		Bureaucrat &operator =( const Bureaucrat &rhs );

		std::string const getName( void ) const;
		int getGrade( void ) const;
		void Promote( void );
		void Demote( void );

	private:
		const std::string name_;
		int grade_;
};

std::ostream &operator <<( std::ostream &out, const Bureaucrat &src );

#endif //BUREAUCRAT_HPP
