
#include "colors.h"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm(72, 45, "RobotomyRequestForm"), _target("Michon")
{
	std::cout << GREEN << "Default RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm(72, 45, "RobotomyRequestForm"), _target(target)
{
	std::cout << LIGHT_GREEN << "Specific  RobotomyRequestForm constructor called" << RESET << std::endl;
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
	return (this->_target);
}



void RobotomyRequestForm::doExecute() const
{
	srand(time(0));

	int chance = std::rand() % 2;
	std::cout << "chance: " << chance << std::endl;
	if (chance)
	{
		std::cout << ITALIC << "BRRRrrrBrrRRrrRRBrrrRRRrrRRBrrrRRrrRRRBrrrRRRRrrRR!" << RESET << std::endl;
		std::cout << LIGHT_BLUE << this->_target << " has been robotomized successfully!" << RESET << std::endl;
	}
	else
		std::cout << LIGHT_BLUE << "The robotomy request on " << this->_target << " has failed!" << RESET << std::endl;
}