
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(const RobotomyRequestForm& cpy);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm& rhs);

		std::string const getTarget() const;
		void	doExecute() const;
};

#endif
