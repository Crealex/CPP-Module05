
#include "colors.h"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
{
	std::cout << GREEN << "Default RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
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
}

