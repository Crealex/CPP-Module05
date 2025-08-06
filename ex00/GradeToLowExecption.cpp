
#include "colors.h"
#include "GradeToLowExecption.hpp"

GradeToLowExecption::GradeToLowExecption():
{
	std::cout << GREEN << "Default GradeToLowExecption constructor called" << RESET << std::endl;
}

GradeToLowExecption::GradeToLowExecption(const GradeToLowExecption &cpy)
{
	std::cout << BLUE << "Copy GradeToLowExecption constructor called" << RESET << std::endl;
}

GradeToLowExecption::~GradeToLowExecption()
{
	std::cout << RED << "GradeToLowExecption destructor called" << RESET << std::endl;
}

GradeToLowExecption &GradeToLowExecption::operator=(const GradeToLowExecption &rhs)
{
	std::cout << LIGHT_BLUE << "GradeToLowExecption assignment operator called" << RESET << std::endl;
}

