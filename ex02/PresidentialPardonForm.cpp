/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:08:01 by anarama           #+#    #+#             */
/*   Updated: 2024/10/16 18:27:52 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm("president", 25, 5, false) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) :
	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec(), other.getIsSigned()), _target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other) {
		this->setIsSigned(other.getIsSigned());
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

void PresidentialPardonForm::execute( Bureaucrat const& executor ) const {
	if (executor.getGrade() > this->getGradeToSign() 
	&& executor.getGrade() > this->getGradeToExec()) {
		std::cout << "Presidential pardon refused!" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "< Makes some drilling noises... >" << std::endl;
	std::cout << this->getTarget() << " has been robotomized successfully 50\% of the time!" << std::endl;
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return this->_target;
}