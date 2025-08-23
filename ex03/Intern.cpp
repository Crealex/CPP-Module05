
#include "colors.h"
#include "Intern.hpp"

// *** CONSTRUCTOR / DESTRUCTOR ***

Intern::Intern()
{
	std::cout << GREEN << "Default Intern constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	(void)cpy;
	std::cout << BLUE << "Copy Intern constructor called" << RESET << std::endl;
}

Intern::~Intern()
{
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

// *** OVERLAOD OPERATOR ***

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	std::cout << LIGHT_BLUE << "Intern assignment operator called" << RESET << std::endl;
	return (*this);
}

// *** METHODS ***

AForm *Intern::createShrubery(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresident(std::string const & target)
{
	return (new PresidentPardonForm(target));
}

AForm *Intern::makeForm(std::string const & name, std::string const & target)
{
	std::string	names[3] = {"shrubbery creation", "robotomy request", "president pardon"};
	AForm		*(Intern::*form[3])(std::string const &) = {&Intern::createShrubery , &Intern::createRobotomy, &Intern::createPresident};
	for (size_t i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << LIGHT_BLUE << "Intern create " << name << " with the target " << target << RESET << std::endl;
			return ((this->*form[i])(target));
		}
	}
	throw Intern::InvalidFormException();
}

// *** EXCEPTION ***

const char *Intern::InvalidFormException::what() const throw()
{
	return ("Invalid form name!");
}