
#ifndef GRADETOLOWEXECPTION_HPP
# define GRADETOLOWEXECPTION_HPP

# include <iostream>

class GradeToLowExecption: public std::exception
{
	private:

	public:
		virtual const char *what();
};

#endif
