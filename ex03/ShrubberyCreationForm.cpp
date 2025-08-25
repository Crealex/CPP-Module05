
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy): AForm(cpy.getGradeToSign(), cpy.getGradeToExec(), cpy.getName()), _target(cpy.getTarget())
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

std::string const &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::doExecute() const
{
	std::string filename(this->_target + "_shrubbery");
	std::ifstream treefile("Tree_ascii_art");
	std::ofstream shrubbery(filename.c_str());
	std::string line;

	while (std::getline(treefile, line))
		shrubbery << line << std::endl;
	std::cout << BOLD << this->_target << "_shrubbery has been created!" << RESET << std::endl;
	shrubbery.close();
	treefile.close();
}
