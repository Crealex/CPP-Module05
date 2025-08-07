
#include "colors.h"
#include "Form.hpp"

Form::Form(): _name("Boring form"), _isSigned(0), _gradeToSign(100), _gradeToExec(50)
{
	std::cout << GREEN << "Default Form constructor called" << RESET << std::endl;
}

Form::Form(const Form &cpy): _name(cpy._name), _isSigned(cpy._isSigned), _gradeToSign(cpy._gradeToSign), _gradeToExec(cpy._gradeToExec)
{
	std::cout << BLUE << "Copy constructor Form called" << RESET << std::endl;
}

Form::~Form()
{
	std::cout << RED << "Destructor Form called" << RESET << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << LIGHT_BLUE << "Form assignment operator called" << RESET << std::endl;
	if (this->_isSigned != rhs._isSigned)
		this->_isSigned = rhs._isSigned;
	if (this->_gradeToSign != rhs._gradeToSign)
		this->_gradeToSign = rhs._gradeToSign;
	if (this->_gradeToExec != rhs._gradeToExec)
		this->_gradeToExec = this->_gradeToSign;
	return (*this);
}

