
#include "colors.h"
#include "Bureaucrat.hpp"

// *** CONSTRUCTOR / DESTRUCTOR ***

Bureaucrat::Bureaucrat():_name("Alphonso, l'esclave d'une societe capitaliste de plus en plus vacillante meme carrement en declin de ouf enfaite"), _grade(150)
{
	std::cout << LIGHT_CYAN << ITALIC << "Default Bureaucrat constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade, std::string const name) throw (std::exception&): _name(name)
{
	std::cout << LIGHT_CYAN << ITALIC << "Specific Bureaucrat constructor called" << RESET << std::endl;
	checkValidity(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): _name(cpy._name), _grade(cpy._grade)
{
	std::cout << BLUE << "Copy Bureaucrat constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}

// *** OPERATOR OVERLOAD ***

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << LIGHT_BLUE << "Bureaucrat assignment operator called" << RESET << std::endl;
	this->_grade = rhs._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &rhs)
{
	stream << rhs.getName() << " bureaucrat grade " << rhs.getGrade();
	return (stream);
}

// *** EXCEPTION ***

const char *Bureaucrat::GradeToHighException::what() const throw()
{
	return ("Grade to high!");
}

const char *Bureaucrat::GradeToLowException::what() const throw()
{
	return ("Grade to low!");
}

// *** METHODS ***

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::downgrade() throw (std::exception&)
{
	checkValidity(this->_grade + 1);
	this->_grade++;
}

void Bureaucrat::upgrade() throw (std::exception&)
{
	checkValidity(this->_grade - 1);
	this->_grade--;
}

void Bureaucrat::checkValidity(int grade) throw(std::exception&)
{
	if (grade > 150)
		throw (Bureaucrat::GradeToLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeToHighException());
}