
#include "colors.h"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _grade(150), _name("Alphonso, l'esclave d'une societe capitaliste de plus en plus vacillante")
{
	std::cout << GREEN << "Default Bureaucrat constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade, std::string const name): _name(name)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
	std::cout << BLUE << "Copy Bureaucrat constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << LIGHT_BLUE << "Bureaucrat assignment operator called" << RESET << std::endl;
}

