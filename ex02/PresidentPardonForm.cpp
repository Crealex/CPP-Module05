
#include "colors.h"
#include "PresidentPardonForm.hpp"

PresidentPardonForm::PresidentPardonForm():
{
	std::cout << GREEN << "Default PresidentPardonForm constructor called" << RESET << std::endl;
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

