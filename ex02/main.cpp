/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:51:53 by anarama           #+#    #+#             */
/*   Updated: 2024/10/29 14:24:37 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat bur1;

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
	PresidentialPardonForm prForm("target");
	try {
		bur1.setGrade(2);
		bur1.executeForm(prForm);
	} catch (const std::exception& e) {
		std::cerr << "Caught some other std::exception " << e.what() << std::endl;
	}
}
