#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeIsOutOfRange::what( void ) const noexcept
{
	const std::string kMsg = "Grade is out of range.";

	return (kMsg.c_str());
}

const char *Bureaucrat::GradeTooHighException::what( void ) const noexcept
{
	const std::string kMsg = "Grade is too high.";

	return (kMsg.c_str());
}

const char *Bureaucrat::GradeTooLowException::what( void ) const noexcept
{
	const std::string kMsg = "Grade is too low.";

	return (kMsg.c_str());
}
