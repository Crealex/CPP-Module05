
#ifndef PRESIDENTPARDONFORM_HPP
# define PRESIDENTPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentPardonForm: public AForm
{
	private:
		std::string	_target;

	public:
		PresidentPardonForm();
		PresidentPardonForm(std::string const & target);
		PresidentPardonForm(const PresidentPardonForm& cpy);
		~PresidentPardonForm();
		PresidentPardonForm &operator=(const PresidentPardonForm& rhs);

		std::string const	&getTarget() const;
		void				doExecute() const;
};

#endif
