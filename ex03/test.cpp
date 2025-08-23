#include "Intern.hpp"
#include "PresidentPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <ctime>
#include <cstdlib>
#include "colors.h"

int	main(void)
{
	Bureaucrat	*b = NULL;
	AForm		*p = NULL;
	AForm		*r = NULL;
	AForm		*s = NULL;
	Intern		*i = NULL;
	std::srand(std::time(NULL));

	std::cout << std::endl << GREEN << BOLD << "Welcome again to this wonderful program. Let's start afresh now with some interns making our forms." << RESET << std::endl;

	/*----------------------------------------------------------------------------------------------------------*/
	/* CREATING HEAP INSTANCES WITH BUREAUCRAT NOT ALLOWED TO SIGN                                              */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "Let's create a lowly bureaucrat and a bunch of forms" << RESET << std::endl;
	try
	{
		b = new Bureaucrat(146, "Low man on the totem pole");
		std::cout << *b << std::endl;
		i = new Intern();
		p = i->makeForm("president pardon", "John Doe");
		std::cout << *p << std::endl;
		r = i->makeForm("robotomy request", "Bocal");
		std::cout << *r << std::endl;
		s = i->makeForm("shrubbery creation", "Your garden");
		std::cout << *s << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Allocation failed: " << e.what() << RESET << std::endl;
		delete b;
		delete p;
		delete r;
		delete s;
		delete i;
		return 1;
	}

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO SIGN ALL FORMS                                                                                    */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "Now, let's let's see what happens when the bureaucrat is not allowed to sign any forms" << RESET << std::endl;
	try
	{
		p->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	try
	{
		r->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET<< std::endl;
	}
	try
	{
		s->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO EXECUTE ALL FORMS                                                                                    */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And what happens if we attempt to execute unsigned forms?" << RESET << std::endl;
	try
	{
		p->execute(*b);
	}
	catch (const AForm::NotSignedException &inse)
	{
		std::cerr << RED << inse.what() << RESET << std::endl;
	}
	try
	{
		r->execute(*b);
	}
	catch (const AForm::NotSignedException &inse)
	{
		std::cerr << RED << inse.what() << RESET << std::endl;
	}
	try
	{
		s->execute(*b);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	delete b;
	b = NULL;

	/*----------------------------------------------------------------------------------------------------------*/
	/* CREATE NEW HEAP INSTANCE OF BUREAUCRAT ONLY ALLOWED TO SIGN SHRUBBERY                                    */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And now let's create a bureaucrat allowed to sign for a shrubbery" << RESET << std::endl;
	try
	{
		b = new Bureaucrat(145, "I can sign for a shrubbery");
		std::cout << *b << std::endl;
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << RED << "Allocation failed: " << e.what() << RESET << std::endl;
		delete b;
		delete p;
		delete r;
		delete s;
		delete i;
		return 1;
	}

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO SIGN ALL FORMS                                                                                    */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "Now, let's let's see what happens when the bureaucrat is not allowed to sign any forms" << RESET << std::endl;
	try
	{
		p->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	try
	{
		r->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	try
	{
		s->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	std::cout << *s << std::endl;

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO EXECUTE SHRUBBERY FORM                                                                            */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And what happens if we attempt to execute the newly signed form?" << RESET << std::endl;
	try
	{
		s->execute(*b);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	delete b;
	b = NULL;

	/*----------------------------------------------------------------------------------------------------------*/
	/* CREATE NEW HEAP INSTANCE OF BUREAUCRAT ALLOWED TO SIGN AND EXECUTE SHRUBBERY                             */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And now let's create a bureaucrat allowed to execute a shrubbery" << RESET << std::endl;
	try
	{
		b = new Bureaucrat(137, "I execute a shrubbery");
		std::cout << *b << std::endl;
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << RED << "Allocation failed: " << e.what() << RESET << std::endl;
		delete b;
		delete p;
		delete r;
		delete s;
		delete i;
		return 1;
	}

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO EXECUTE SHRUBBERY FORM                                                                            */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "Let's try executing again..." << RED << " Don't forget to check for the file ;-)" << RESET << std::endl;
	try
	{
		s->execute(*b);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	delete b;
	b = NULL;

	/*----------------------------------------------------------------------------------------------------------*/
	/* CREATE NEW HEAP INSTANCE OF BUREAUCRAT ONLY ALLOWED TO SIGN ROBOTOMY                                     */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And now let's create a bureaucrat allowed to sign for a robotomy" << RESET << std::endl;
	try
	{
		b = new Bureaucrat(72, "I can sign for a robotomy");
		std::cout << *b << std::endl;
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << RED << "Allocation failed: " << e.what() << RESET << std::endl;
		delete b;
		delete p;
		delete r;
		delete s;
		delete i;
		return 1;
	}

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO SIGN ALL FORMS                                                                                    */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "Now, let's let's see what happens when the bureaucrat is only allowed to sign for shrubbery and robotomy" << RESET << std::endl;
	try
	{
		p->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	try
	{
		r->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	try
	{
		s->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	std::cout << *s << std::endl;
	std::cout << *r << std::endl;

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO EXECUTE ROBOTOMY FORM                                                                             */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And what happens if we attempt to execute the newly signed form?" << RESET << std::endl;
	try
	{
		r->execute(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}

	delete b;
	b = NULL;

	/*----------------------------------------------------------------------------------------------------------*/
	/* CREATE NEW HEAP INSTANCE OF BUREAUCRAT ALLOWED TO SIGN AND EXECUTE ROBOTOMY                              */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And now let's create a bureaucrat allowed to execute a robotomy" << RESET << std::endl;
	try
	{
		b = new Bureaucrat(45, "I execute a robotomy");
		std::cout << *b << std::endl;
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << RED << "Allocation failed: " << e.what() << RESET << std::endl;
		delete b;
		delete p;
		delete r;
		delete s;
		delete i;
		return 1;
	}

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO EXECUTE ROBOTOMY FORM                                                                             */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "Let's try executing again..." << RESET << std::endl;
	try
	{
		r->execute(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}

	delete b;
	b = NULL;

	/*----------------------------------------------------------------------------------------------------------*/
	/* CREATE NEW HEAP INSTANCE OF BUREAUCRAT ONLY ALLOWED TO SIGN PARDON                                       */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And now let's create a bureaucrat allowed to sign for a presidential pardon" << RESET << std::endl;
	try
	{
		b = new Bureaucrat(25, "I can sign for a pardon");
		std::cout << *b << std::endl;
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << RED << "Allocation failed: " << e.what() << RESET << std::endl;
		delete b;
		delete p;
		delete r;
		delete s;
		delete i;
		return 1;
	}

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO SIGN ALL FORMS                                                                                    */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "Now, let's let's see what happens when the bureaucrat is not allowed to sign any forms" << RESET << std::endl;
	try
	{
		p->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	try
	{
		r->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	try
	{
		s->beSigned(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	std::cout << *s << std::endl;
	std::cout << *r << std::endl;
	std::cout << *p << std::endl;

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO EXECUTE PARDON FORM                                                                               */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And what happens if we attempt to execute the newly signed form?" << RESET << std::endl;
	try
	{
		p->execute(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}

	delete b;
	b = NULL;

	/*----------------------------------------------------------------------------------------------------------*/
	/* CREATE NEW HEAP INSTANCE OF BUREAUCRAT ALLOWED TO SIGN AND EXECUTE PARDON                                */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "And now let's create a bureaucrat allowed to execute a presidential pardon" << RESET << std::endl;
	try
	{
		b = new Bureaucrat(5, "I execute a pardon");
		std::cout << *b << std::endl;
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << RED << "Allocation failed: " << e.what() << RESET << std::endl;
		delete b;
		delete p;
		delete r;
		delete s;
		delete i;
		return 1;
	}

	/*----------------------------------------------------------------------------------------------------------*/
	/* TRY TO EXECUTE ALL FORMS                                                                                 */
	/*----------------------------------------------------------------------------------------------------------*/

	std::cout << std::endl << BLUE << "Let's try executing all forms again..." << RED << " Don't forget to check for the shrubbery file ;-)" << RESET << std::endl;
	try
	{
		s->execute(*b);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		r->execute(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}
	try
	{
		p->execute(*b);
	}
	catch (const AForm::GradeTooLowException &gtle)
	{
		std::cerr << RED << gtle.what() << RESET << std::endl;
	}

	delete b;
	delete p;
	delete s;
	delete r;
	delete i;

	std::cout << std::endl << GREEN << "That seems to work nicely! Thanks for joining us for this experiment, see you again soon in ex02!" << RESET << std::endl << std::endl;
	return 0;
}