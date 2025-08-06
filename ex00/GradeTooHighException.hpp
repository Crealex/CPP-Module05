
#ifndef GRADETOOHIGHEXCEPTION_HPP
# define GRADETOOHIGHEXCEPTION_HPP

# include <iostream>

class GradeTooHighException : public std::exception
{
	private:

	public:
		virtual	const char *what();
};

#endif
