
#include "colors.h"
#include "Form.hpp"

// *** CONSTRUCTOR / DESTRUCTOR ***

Form::Form(): _name("Boring form"), _isSigned(0), _gradeToSign(100), _gradeToExec(50)
{
	std::cout << GREEN << "Default Form constructor called" << RESET << std::endl;
}

Form::Form(int toSign, int toExec, std::string name): _name(name), _isSigned(0), _gradeToSign(toSign), _gradeToExec(toExec)
{
	std::cout << LIGHT_GREEN << "Constructor Form called" << RESET << std::endl;
	checkValidity(toSign);
	checkValidity(toExec);
}

Form::Form(const Form &cpy): _name(cpy._name), _isSigned(cpy._isSigned), _gradeToSign(cpy._gradeToSign), _gradeToExec(cpy._gradeToExec)
{
	std::cout << BLUE << "Copy constructor Form called" << RESET << std::endl;
}

Form::~Form()
{
	std::cout << RED << "Destructor Form called" << RESET << std::endl;
}

// *** OPERATOR OVERLOAD ***

Form &Form::operator=(const Form &rhs)
{
	std::cout << LIGHT_BLUE << "Form assignment operator called" << RESET << std::endl;
	if (this->_isSigned != rhs._isSigned)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Form &rhs)
{
	stream << rhs.getName() << " needed grade " << rhs.getGradeToSign() << " to be signed and grade " << rhs.getGradeToExec() << " to be exec " << std::endl;
	if (rhs.getIsSigned())
		stream << rhs.getName() << " is signed" << std::endl;
	else
		stream << rhs.getName() << " is not signed" << std::endl;
	return (stream);
}

// *** METHODS

void Form::checkValidity(int grade)
{
	if (grade > 150)
		throw (Form::GradeTooLowException());
	else if (grade < 1)
		throw (Form::GradeTooHighException());
}

const std::string Form::getName() const
{
	return (this->_name);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

void Form::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		if (this->_isSigned)
			std::cout << BLUE << this->getName() << "already signed" << RESET << std::endl;
		else
		{
			this->_isSigned = true;
			std::cout << BLUE << bureaucrat.getName() << " signed " << this->getName() << RESET << std::endl;
		}
	}
	else
		throw (Form::GradeTooLowException());
}

// *** EXCEPTIONS ***

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}
