/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:51:47 by anarama           #+#    #+#             */
/*   Updated: 2024/10/30 10:12:44 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( void ) : _name(DEFAULT_NAME), _grade(DEFAULT_GRADE) {}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _grade(other._grade) {}

Bureaucrat::Bureaucrat( std::string const& name, int grade ) : _name(name), _grade(grade) {
	validateGrade(grade);
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::string const& Bureaucrat::getName( void ) const {
	return this->_name;
}

int Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void Bureaucrat::setGrade( int grade ) {
	this->_grade = grade;
	validateGrade(grade);
}

void Bureaucrat::incrementGrade( void ) {
	this->_grade--;
	validateGrade(this->_grade);
}

void Bureaucrat::decrementGrade( void ) {
	this->_grade++;
	validateGrade(this->_grade);
}

void Bureaucrat::validateGrade( int grade ) const {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream& operator<<( std::ostream& out, const Bureaucrat& other ) {
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return out;
}

void Bureaucrat::signForm( AForm & form ) {
	form.beSigned(*this);
}

void Bureaucrat::executeForm( AForm const & form ) {
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}