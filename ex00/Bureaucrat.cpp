/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:51:47 by anarama           #+#    #+#             */
/*   Updated: 2024/10/16 12:22:24 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name(DEFAULT_NAME), _grade(DEFAULT_GRADE) {}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _grade(other._grade) {}

Bureaucrat::Bureaucrat( std::string const& name, int grade ) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
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
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::incrementGrade( void ) {
	this->_grade--;
	if (this->_grade < 1) {
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::decrementGrade( void ) {
	this->_grade++;
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream& operator<<( std::ostream& out, const Bureaucrat& other ) {
	out << other.getGrade();
	return out;
}
