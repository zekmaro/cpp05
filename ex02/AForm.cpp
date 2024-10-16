/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:24:08 by anarama           #+#    #+#             */
/*   Updated: 2024/10/16 18:30:58 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) :
	_name(DEFAULT_FORM_NAME),
	_gradeToSign(DEFAULT_GRADE_TO_SIGN),
	_gradeToExec(DEFAULT_GRADE_TO_EXEC),
	_isSigned(DEFAULT_IS_SIGNED) {}
						
AForm::AForm( const AForm& other ) :
	_name(other.getName()),
	_gradeToSign(other.getGradeToSign()),
	_gradeToExec(other.getGradeToExec()),
	_isSigned(other.getIsSigned()) {
		
	validateGradeForm(other.getGradeToSign());
	validateGradeForm(other.getGradeToExec());
}

AForm::AForm( std::string const name, int const gradeToSign,
				int const gradeToExec, bool isSigned) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec),
	_isSigned(isSigned) {}

AForm& AForm::operator=( const AForm& other ) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm( void ) {}

std::string const& AForm::getName( void ) const {
	return this->_name;
}

int AForm::getGradeToSign( void ) const {
	return this->_gradeToSign;	
}

int AForm::getGradeToExec( void ) const {
	return this->_gradeToExec;
}

bool AForm::getIsSigned( void ) const {
	return this->_isSigned;	
}

bool AForm::setIsSigned( bool isSigned ) {
	this->_isSigned = isSigned;
}

void validateGradeForm( int grade ) {
	if (grade < 1) {
		throw AForm::GradeTooHighException();
	} else if (grade > 150) {
		throw AForm::GradeTooLowException();
	}
}

void AForm::beSigned( const Bureaucrat& b ) {
	if (b.getGrade() <= this->getGradeToSign()) {
		this->setIsSigned(true);
		b.signForm(this->getName());
	}
	else {
		std::cout << b.getGrade() << "couldn’t sign " << this->getName() << " because grade was too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
}
