
#include "colors.h"
#include "AForm.hpp"

// *** CONSTRUCTOR / DESTRUCTOR ***

AForm::AForm(): _name("Boring form"), _isSigned(0), _gradeToSign(100), _gradeToExec(50)
{
	std::cout << GREEN << "Default AForm constructor called" << RESET << std::endl;
}

AForm::AForm(int toSign, int toExec, std::string name): _name(name), _isSigned(0), _gradeToSign(toSign), _gradeToExec(toExec)
{
	std::cout << LIGHT_GREEN << "Constructor AForm called" << RESET << std::endl;
	checkValidity(toSign);
	checkValidity(toExec);
}

AForm::AForm(const AForm &cpy): _name(cpy._name), _isSigned(cpy._isSigned), _gradeToSign(cpy._gradeToSign), _gradeToExec(cpy._gradeToExec)
{
	std::cout << BLUE << "Copy constructor AForm called" << RESET << std::endl;
}

AForm::~AForm()
{
	std::cout << RED << "Destructor AForm called" << RESET << std::endl;
}

// *** OPERATOR OVERLOAD ***

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << LIGHT_BLUE << "AForm assignment operator called" << RESET << std::endl;
	if (this->_isSigned != rhs._isSigned)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const AForm &rhs)
{
	stream << rhs.getName() << " needed grade " << rhs.getGradeToSign() << " to be signed and grade " << rhs.getGradeToExec() << " to be exec " << std::endl;
	if (rhs.getIsSigned())
		stream << rhs.getName() << " is signed" << std::endl;
	else
		stream << rhs.getName() << " is not signed" << std::endl;
	return (stream);
}

// *** METHODS

void AForm::checkValidity(int grade)
{
	if (grade > 150)
		throw (AForm::GradeTooLowException());
	else if (grade < 1)
		throw (AForm::GradeTooHighException());
}

const std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

void AForm::beSigned(const Bureaucrat & bureaucrat)
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
		throw (AForm::GradeTooLowException());
}

void AForm::execute(const Bureaucrat & executor) const
{
	if (!this->getIsSigned())
		throw (AForm::NotSignedException());
	if (executor.getGrade() <= this->getGradeToExec())
		this->doExecute();
	else
		throw (AForm::GradeTooLowException());
}

// *** EXCEPTIONS ***

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("The form is not signed!");
}
