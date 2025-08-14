
#include "colors.h"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(145, 137, "ShrubberyCreationForm"), _target("Interstellar_void")
{
	std::cout << GREEN << "Default ShrubberyCreationForm constructor called" << RESET << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target): AForm(145, 137, "ShruberryCreationForm"), _target(target)
{
	std::cout << LIGHT_GREEN << "Specific ShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy): AForm(145, 137, "ShrubberyCreationForm"), _target(cpy._target)
{
	std::cout << BLUE << "Copy ShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this->_target != rhs._target)
		this->_target = rhs._target;
	std::cout << LIGHT_BLUE << "ShrubberyCreationForm assignment operator called" << RESET << std::endl;
	return (*this);
}

// *** METHODDS ***

void ShrubberyCreationForm::doExecute() const
{
	std::string filename(this->_target + "_shrubbery");
	std::ofstream shrubbery(filename.c_str());

	shrubbery << "Beautifull tree in ascii art";
	shrubbery.close();
}