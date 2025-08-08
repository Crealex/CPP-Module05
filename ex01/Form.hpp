
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

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
		Form(const Form& cpy);
		~Form();
		Form &operator=(const Form& rhs);

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

#endif FORM_HPP