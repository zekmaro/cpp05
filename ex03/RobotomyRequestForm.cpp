/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:08:01 by anarama           #+#    #+#             */
/*   Updated: 2024/10/17 13:57:46 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) :
	AForm("robotomy", 72, 45, false) {}

RobotomyRequestForm::RobotomyRequestForm( std::string const& target ) :
	AForm("robotomy", 72, 45, false), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) :
	AForm(	other.getName(),
			other.getGradeToSign(),
			other.getGradeToExec(),
			other.getIsSigned() ) ,
	_target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	if (this != &other) {
		this->setIsSigned(other.getIsSigned());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

void RobotomyRequestForm::execute( Bureaucrat const& executor ) const {
	if (this->getIsSigned() == false) {
		throw RobotomyRequestForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExec()) {
		std::cout << "Robotomy failed!" << std::endl;
		throw RobotomyRequestForm::GradeTooLowException();
	}
	std::cout << "< Makes some drilling noises... >" << std::endl;
	std::cout << this->getTarget() << " has been robotomized successfully 50\% of the time!" << std::endl;
}

std::string RobotomyRequestForm::getTarget( void ) const {
	return this->_target;
}