
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:

		std::string const	_name;
		int					_grade;

		void				checkValidity(int grade);

		public:

		Bureaucrat();
		Bureaucrat(int grade, std::string const name);
		Bureaucrat(const Bureaucrat& cpy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat& rhs);

		std::string	const	&getName() const;
		int					getGrade() const;
		void				upgrade();
		void				downgrade();
		void				signForm(Form &form) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat& rhs);

#endif
