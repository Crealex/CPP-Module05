
#include "colors.h"
#include "GradeTooHighException.hpp"

const char *GradeTooHighException::what()
{
	return ("Grade too high!");
}