
#include "colors.h"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm(72, 45, "RobotomyRequestForm"), _target("Michon")
{
	std::cout << GREEN << "Default RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm(72, 45, "RobotomyRequestForm"), _target(target)
{
	std::cout << LIGHT_GREEN << "Default RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy): AForm(cpy.getGradeToSign(), cpy.getGradeToExec(), cpy.getName()), _target(cpy.getTarget())
{
	std::cout << BLUE << "Copy RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << LIGHT_BLUE << "RobotomyRequestForm assignment operator called" << RESET << std::endl;
	if (rhs._target != this->_target)
		this->_target = rhs._target;
	return (*this);
}

// *** METHODS ***

std::string const RobotomyRequestForm::getTarget() const
{
	return (this->getTarget());
}