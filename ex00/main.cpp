/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:51:53 by anarama           #+#    #+#             */
/*   Updated: 2024/10/17 11:25:48 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat bur1;

	try {
		bur1.setGrade(200);
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
	std::cout << bur1;
	Bureaucrat bur2("Anton", 20);
	std::cout << bur2;
	try {
		Bureaucrat bur3("Anton", 0);
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
	}
}
