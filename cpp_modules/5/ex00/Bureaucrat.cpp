#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name_(""), grade_(150)
{
	const std::string kMsg = "default constructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src )
{
	const std::string kMsg = "copy constructor called";

	*this = src;
	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name ) : name_(name), grade_(150)
{
	const std::string kMsg = "Naming constructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name, const int grade ) : name_(name), grade_(grade)
{
	const std::string kMsg = "Naming and Grading constructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const int grade ) : name_("")
{
	const std::string kMsg = "Grading constructor called";

	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade_ = grade;

	std::cout << kMsg << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	const std::string kMsg = "Destructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat &Bureaucrat::operator =( const Bureaucrat &rhs )
{
	const std::string kMsg = "Assignation operator called";

	if (this != &rhs)
	{
		*this = Bureaucrat(rhs.getName(), rhs.getGrade());
	}
	std::cout << kMsg << std::endl;

	return (*this);
}

std::ostream &operator <<( std::ostream &out, const Bureaucrat &src )
{
	out << src.getName() + ", " << "bureaucrat grade ";
	out << src.getGrade() + "." << std::endl;
	return (out);
}

std::string const Bureaucrat::getName( void ) const
{
	return (this->name_);
}

int Bureaucrat::getGrade( void ) const
{
	return (this->grade_);
}

void Bureaucrat::Promote( void )
{
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeIsOutOfRange();
	else
		this->grade_ -= 1;
}

void Bureaucrat::Demote( void )
{
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeIsOutOfRange();
	else
		this->grade_ += 1;
}
