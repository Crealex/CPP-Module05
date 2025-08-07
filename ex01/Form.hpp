
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

	public:
		Form();
		Form(const Form& cpy);
		~Form();
		Form &operator=(const Form& rhs);
};

#endif FORM_HPP