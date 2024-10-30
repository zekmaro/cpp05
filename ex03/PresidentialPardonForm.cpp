/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:08:01 by anarama           #+#    #+#             */
/*   Updated: 2024/10/30 10:51:04 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm("Presidential Pardon ", 25, 5, false) {}

PresidentialPardonForm::PresidentialPardonForm( std::string const& target ) :
	AForm("Presidential Pardon", 25, 5, false), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) :
	AForm(	other.getName(),
			other.getGradeToSign(),
			other.getGradeToExec(),
			other.getIsSigned() ),
	_target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other) {
		this->setIsSigned(other.getIsSigned());
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

void PresidentialPardonForm::execute( Bureaucrat const& executor ) const {
	if (this->getIsSigned() == false) {
		std::cout << "Presidential form was not sighed yet!" << std::endl;
		throw PresidentialPardonForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExec()) {
		std::cout << "Presidential pardon refused!" << std::endl;
		throw PresidentialPardonForm::GradeTooLowException();
	}
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return this->_target;
}