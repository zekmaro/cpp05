/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:24:08 by anarama           #+#    #+#             */
/*   Updated: 2024/10/30 10:11:05 by anarama          ###   ########.fr       */
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
	_isSigned(isSigned) {
	validateGradeForm(gradeToSign);
	validateGradeForm(gradeToExec);	
}

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

void AForm::setIsSigned( bool isSigned ) {
	this->_isSigned = isSigned;
}

void AForm::validateGradeForm( int grade ) {
	if (grade < 1) {
		throw AForm::GradeTooHighException();
	} else if (grade > 150) {
		throw AForm::GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form was not signed yet!";
}

void AForm::beSigned( const Bureaucrat& b ) {
	if (b.getGrade() <= this->getGradeToSign()) {
		if (this->getIsSigned() == false) {
			this->setIsSigned(true);
			std::cout << this->getName() << " form was successfuly signed" << std::endl;
		} else if (this->getIsSigned() == true) {
			std::cout << this->getName() << " form was already signed" << std::endl;
		}
	} else {
		std::cout << b.getName() << " couldn’t sign " << this->getName() << " because grade was too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
}

std::ostream& operator<<( std::ostream& out, const AForm& other ) {
	out << 
		"name: " << other.getName() << std::endl << 
		"grade to sign: " << other.getGradeToSign() << std::endl <<
		"grade to exec: " << other.getGradeToExec() << std::endl <<
		"is signed: " << other.getIsSigned() << std::endl;

	return out;
}
