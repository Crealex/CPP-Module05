
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
private:

public:
Intern();
Intern(const Intern& cpy);
~Intern();
Intern &operator=(const Intern& rhs);

AForm *makeForm(std::string & name, std::string & target);

};

#endif
