/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:24:08 by anarama           #+#    #+#             */
/*   Updated: 2024/10/17 12:04:13 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) :
	_name(DEFAULT_FORM_NAME),
	_gradeToSign(DEFAULT_GRADE_TO_SIGN),
	_gradeToExec(DEFAULT_GRADE_TO_EXEC),
	_isSigned(DEFAULT_IS_SIGNED) {}
						
Form::Form( const Form& other ) :
	_name(other.getName()),
	_gradeToSign(other.getGradeToSign()),
	_gradeToExec(other.getGradeToExec()),
	_isSigned(other.getIsSigned()) {
		
	validateGradeForm(other.getGradeToSign());
	validateGradeForm(other.getGradeToExec());
}

Form& Form::operator=( const Form& other ) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form( void ) {}

std::string const& Form::getName( void ) const {
	return this->_name;
}

int Form::getGradeToSign( void ) const {
	return this->_gradeToSign;	
}

int Form::getGradeToExec( void ) const {
	return this->_gradeToExec;
}

bool Form::getIsSigned( void ) const {
	return this->_isSigned;	
}

void Form::setIsSigned( bool isSigned ) {
	this->_isSigned = isSigned;
}

void Form::validateGradeForm( int grade ) {
	if (grade < 1) {
		throw Form::GradeTooHighException();
	} else if (grade > 150) {
		throw Form::GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Form::beSigned( const Bureaucrat& b ) {
	if (b.getGrade() <= this->getGradeToSign()) {
		this->setIsSigned(true);
		b.signForm(this->getName());
	}
	else {
		std::cout << b.getGrade() << "couldn’t sign " << this->getName() << " because grade was too low" << std::endl;
		throw Form::GradeTooLowException();
	}
}
