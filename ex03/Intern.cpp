/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:09:25 by anarama           #+#    #+#             */
/*   Updated: 2024/10/30 11:37:20 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern( void ) {
	this->initFormNames();
}

Intern::Intern( const Intern& other ) {
	for (int i = 0; i < 3; i++) {
		this->_formNames[i] = other._formNames[i];
	}
}

Intern& Intern::operator=( const Intern& other ) {
	if (this != &other) {
		for (int i = 0; i < 3; i++) {
			this->_formNames[i] = other._formNames[i];
		}
	}
	return *this;
}

Intern::~Intern( void ) {}

AForm* Intern::makeForm( std::string const& formName, std::string const& target) const {
	int i = 0;
	for (i = 0; i < 3; i++) {
		if (this->_formNames[i] == formName) {
			break ;
		}
	}
	AForm* form = NULL;
	switch (i) {
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "No match found!" << std::endl;
			throw Intern::FormDoesntExistException();
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}

const char* Intern::FormDoesntExistException::what() const throw() {
    return "Form doesnt exist!";
}

void Intern::initFormNames( void ) {
	this->_formNames[0] = FORM_NAME_SHRUBBERY;
	this->_formNames[1] = FORM_NAME_ROBOTOMY;
	this->_formNames[2] = FORM_NAME_PRESIDENT;
}