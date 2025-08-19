
#include "colors.h"
#include "PresidentPardonForm.hpp"

PresidentPardonForm::PresidentPardonForm(): AForm(25, 5, "PresidentPardonForm"), _target("Meude")
{
	std::cout << GREEN << "Default PresidentPardonForm constructor called" << RESET << std::endl;
}

PresidentPardonForm::PresidentPardonForm(std::string const & target): AForm(25, 5, "PresidentPardonForm"), _target(target)
{
	std::cout << LIGHT_GREEN << "Specific PresidentPardonForm constructor called" << RESET << std::endl;
}

PresidentPardonForm::PresidentPardonForm(const PresidentPardonForm &cpy)
{
	std::cout << BLUE << "Copy PresidentPardonForm constructor called" << RESET << std::endl;
}

PresidentPardonForm::~PresidentPardonForm()
{
	std::cout << RED << "PresidentPardonForm destructor called" << RESET << std::endl;
}

PresidentPardonForm &PresidentPardonForm::operator=(const PresidentPardonForm &rhs)
{
	std::cout << LIGHT_BLUE << "PresidentPardonForm assignment operator called" << RESET << std::endl;
}

