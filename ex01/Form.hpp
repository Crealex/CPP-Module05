
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		int					_gradeToSign;
		int					_gradeToExec;
		void				checkValidity(int grade);

	public:
		Form();
		Form(int toSign, int ToExec, const std::string name);
		Form(const Form& cpy);
		~Form();
		Form &operator=(const Form& rhs);

		const std::string	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		bool				getIsSigned() const;
		void				beSigned(const Bureaucrat&);

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


std::ostream &operator<<(std::ostream &stream, const Form& rhs);

#endif FORM_HPP