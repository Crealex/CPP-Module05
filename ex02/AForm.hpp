
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

		public:
		AForm();
		AForm(int toSign, int ToExec, const std::string name);
		AForm(const AForm& cpy);
		~AForm();
		AForm &operator=(const AForm& rhs);

		const std::string	&getName() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		bool				getIsSigned() const;
		void				beSigned(const Bureaucrat&);
		void				execute(Bureaucrat const & executor) const;
		virtual void		doExecute() const = 0;

		void				checkValidity(int grade);

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

		class NotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};


std::ostream &operator<<(std::ostream &stream, const AForm& rhs);

#endif