
#include "colors.h"
#include "Bureaucrat.hpp"

// *** CONSTRUCTOR / DESTRUCTOR ***

Bureaucrat::Bureaucrat():_name("Alphonso, l'esclave d'une societe capitaliste de plus en plus vacillante meme carrement en declin de ouf enfaite"), _grade(150)
{
	std::cout << LIGHT_CYAN << ITALIC << "Default Bureaucrat constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string const name): _name(name)
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
	if (this->_grade != rhs._grade)
		this->_grade = rhs._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &rhs)
{
	stream << rhs.getName() << " bureaucrat grade " << rhs.getGrade();
	return (stream);
}

// *** EXCEPTION ***

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

// *** METHODS ***

const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::downgrade()
{
	checkValidity(this->_grade + 1);
	std::cout << LIGHT_YELLOW << "downgrade " << this->_name << RESET << std::endl;
	this->_grade++;
}

void Bureaucrat::upgrade()
{
	checkValidity(this->_grade - 1);
	std::cout << LIGHT_YELLOW << "upgrade " << this->_name << RESET << std::endl;
	this->_grade--;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << LIGHT_RED << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}

}

void Bureaucrat::excecuteForm(AForm & form) const
{
	try
	{
		form.execute(*this);
		std::cout << LIGHT_YELLOW << this->_name << " executed " << form.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << LIGHT_RED << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << RESET << '\n';
	}

}

void Bureaucrat::checkValidity(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}