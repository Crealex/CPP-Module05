
#include "colors.h"
#include "PresidentPardonForm.hpp"

// *** CONSTRUCOTR / DESTRUCTOR ***

PresidentPardonForm::PresidentPardonForm(): AForm(25, 5, "PresidentPardonForm"), _target("Meude")
{
	std::cout << GREEN << "Default PresidentPardonForm constructor called" << RESET << std::endl;
}

PresidentPardonForm::PresidentPardonForm(std::string const & target): AForm(25, 5, "PresidentPardonForm"), _target(target)
{
	std::cout << LIGHT_GREEN << "Specific PresidentPardonForm constructor called" << RESET << std::endl;
}

PresidentPardonForm::PresidentPardonForm(const PresidentPardonForm &cpy): AForm(cpy.getGradeToSign(), cpy.getGradeToExec(), cpy.getName()), _target(cpy._target)
{
	std::cout << BLUE << "Copy PresidentPardonForm constructor called" << RESET << std::endl;
}

PresidentPardonForm::~PresidentPardonForm()
{
	std::cout << RED << "PresidentPardonForm destructor called" << RESET << std::endl;
}

// *** OVERLOAD OPERATOR ***

PresidentPardonForm &PresidentPardonForm::operator=(const PresidentPardonForm &rhs)
{
	std::cout << LIGHT_BLUE << "PresidentPardonForm assignment operator called" << RESET << std::endl;
	if (this->_target != rhs._target)
		this->_target = rhs._target;
	return (*this);
}

// *** METHODS ***

std::string const &PresidentPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentPardonForm::doExecute() const
{
	std::cout << LIGHT_BLUE << this->_target << " has been pardoned by Zaphod Beeblebrox!" << RESET << std::endl;
}