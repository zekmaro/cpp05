/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:51:53 by anarama           #+#    #+#             */
/*   Updated: 2024/10/30 10:11:49 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat bur1("Victor", 1);

	std::cout << "====SOME SIMPLE TESTS====" << std::endl;
	try {
		bur1.setGrade(1);
		bur1.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Caught some other std::exception " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "====SOME PRESIDENTIAL PARDON FORM TESTS====" << std::endl;
	PresidentialPardonForm form1("Andrey");
	try {
		bur1.setGrade(2);
		bur1.signForm(form1);
		bur1.executeForm(form1);
	} catch (const std::exception& e) {
		std::cerr << "Caught some other std::exception " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "====SOME ROBOTOMY REQUEST FORM TESTS====" << std::endl;
	RobotomyRequestForm form2("target");
	try {
		bur1.setGrade(150);
		bur1.signForm(form2);
	} catch (const std::exception& e) {
		std::cerr << "Caught some std::exception " << e.what() << std::endl;
	}
	try {
		bur1.setGrade(72);
		bur1.signForm(form2);
		bur1.executeForm(form2);
	} catch (const std::exception& e) {
		std::cerr << "Caught some std::exception " << e.what() << std::endl;
	}
	try {
		bur1.setGrade(45);
		bur1.signForm(form2);
		bur1.executeForm(form2);
		bur1.executeForm(form2);
	} catch (const std::exception& e) {
		std::cerr << "Caught some std::exception " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "====SOME SHRUBBERY CREATION FORM TESTS====" << std::endl;
	ShrubberyCreationForm form3("home");
	try {
		bur1.setGrade(137);
		bur1.signForm(form3);
		bur1.executeForm(form3);
	} catch (const std::exception& e) {
		std::cerr << "Caught some std::exception " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "====EL PRIMO!!!====" << std::endl;
}
