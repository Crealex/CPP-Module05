
#include "colors.h"
#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Default Intern constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	std::cout << BLUE << "Copy Intern constructor called" << RESET << std::endl;
}

Intern::~Intern()
{
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << LIGHT_BLUE << "Intern assignment operator called" << RESET << std::endl;
}

AForm *Intern::makeForm(std::string & name, std::string & target)
{
	std::cout << LIGHT_BLUE << "Intern create " << name << " with the target " << target << RESET << std::endl;
}