
#ifndef GRADETOLOWEXECPTION_HPP
# define GRADETOLOWEXECPTION_HPP

# include <iostream>

class GradeToLowExecption
{
	private:

	public:
		GradeToLowExecption();
		GradeToLowExecption(const GradeToLowExecption& cpy);
		~GradeToLowExecption();
		GradeToLowExecption &operator=(const GradeToLowExecption& rhs);
};

#endif
