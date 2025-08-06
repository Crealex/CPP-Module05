
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "GradeToLowExecption.hpp"
# include "GradeTooHighException.hpp"

class Bureaucrat: public GradeToLowExecption, public GradeTooHighException
{
	private:

		std::string const		_name;
		unsigned int			_grade;


	public:

		Bureaucrat();
		Bureaucrat(unsigned int grade, std::string const name);
		Bureaucrat(const Bureaucrat& cpy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat& rhs);
		Bureaucrat &operator<<(const Bureaucrat& rhs);
		std::string const getName();
		int getGrade();
};

#endif
