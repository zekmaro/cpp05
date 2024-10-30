/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:51:53 by anarama           #+#    #+#             */
/*   Updated: 2024/10/30 11:26:30 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat bur1("Victor", 1);
	Intern nobody;

	PresidentialPardonForm form1("Andrey");
	RobotomyRequestForm form2("target");
	ShrubberyCreationForm form3("home");

	AForm *form = NULL;
	try {
		form = nobody.makeForm(form1.getName(), form1.getTarget());
		bur1.signForm(*form);
		bur1.executeForm(*form);
		delete form;
		form = NULL;
	} catch (const std::exception& e) {
		if (form != NULL) {
			delete form;
			form = NULL;
		}
		std::cout << "====LIFE SUCKS====" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		form = nobody.makeForm("incorrect name", form1.getTarget());
		bur1.signForm(*form);
		delete form;
		form = NULL;
	} catch (const std::exception& e) {
		if (form != NULL) {
			delete form;
		}
		std::cout << "====LIFE SUCKS====" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << "====EL PRIMO!!!====" << std::endl;
}
