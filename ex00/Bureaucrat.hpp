
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:

		std::string const		_name;
		unsigned int			_grade;

		public:

		Bureaucrat();
		Bureaucrat(unsigned int grade, std::string const name) throw (std::exception&);
		Bureaucrat(const Bureaucrat& cpy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat& rhs);

		std::string	const	getName() const;
		int					getGrade() const;
		void				upgrade() throw (std::exception&);
		void				downgrade() throw(std::exception&);
		void				checkValidity(int grade) throw (std::exception&);

		class GradeToHighException: public std::exception
		{
			public:
			virtual const char *what() const throw();
		};

		class GradeToLowException: public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
	};

	std::ostream &operator<<(std::ostream &stream, const Bureaucrat& rhs);

#endif
