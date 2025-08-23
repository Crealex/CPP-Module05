
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentPardonForm.hpp"

class Intern
{
	private:
		AForm *createShrubery(std::string const & target);
		AForm *createRobotomy(std::string const & target);
		AForm *createPresident(std::string const & target);

	public:
		Intern();
		Intern(const Intern& cpy);
		~Intern();
		Intern &operator=(const Intern& rhs);

		AForm *makeForm(std::string const & name, std::string const & target);

		class InvalidFormException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif
