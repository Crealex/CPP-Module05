/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:58:01 by alexandre         #+#    #+#             */
/*   Updated: 2025/08/12 10:49:41 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "colors.h"

int main()
{
	try // Should not work
	{
		std::cout << BOLD << "Declare a too low grade:" << RESET << std::endl;
		Bureaucrat	yvette(151, "Yvette");
		std::cout << GREEN << yvette << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try // Should not work
	{
		std::cout << BOLD << "Declare a too high grade:" << RESET << std::endl;
		Bureaucrat	yvon(-1, "Yvon");
		std::cout << GREEN << yvon << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try // Should work
	{
		std::cout << BOLD << "Declare a valid grade:" << RESET << std::endl;
		Bureaucrat yvan(1, "Yvan");
		std::cout << GREEN << yvan << RESET << std::endl;
	}
	catch(std:: exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try // Should work
	{
		std::cout << BOLD << "With a default constructor" << RESET << std::endl;
		Bureaucrat alph;
		std::cout << GREEN << alph << RESET << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat yvan(1, "Yvan");
		std::cout << BOLD << "Try to downgrade Yvan" << RESET << std::endl;
		std::cout << "Berfore downgrade:" << std::endl;
		std::cout << GREEN << yvan << RESET << std::endl;
		yvan.downgrade();
		std::cout << "After downgrade:" << std::endl;
		std::cout << GREEN << yvan << RESET << std::endl;
		std::cout << BOLD << "Try to upgrade Yvan two times" << RESET << std::endl;
		yvan.upgrade();
		yvan.upgrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}