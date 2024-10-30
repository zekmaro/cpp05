/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:08:01 by anarama           #+#    #+#             */
/*   Updated: 2024/10/30 10:51:46 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <ostream>

#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	AForm("Schrubbery Creation", 145, 137, false),
	_target(DEFAULT_TARGET_SCHRUBBERY) {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const& target ) :
	AForm("Schrubbery Creation", 145, 137, false), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) :
	AForm(	other.getName(),
			other.getGradeToSign(),
			other.getGradeToExec(),
			other.getIsSigned() ),
	_target(other.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	if (this != &other) {
		this->setIsSigned(other.getIsSigned());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

void ShrubberyCreationForm::execute( Bureaucrat const& executor ) const {
	if (this->getIsSigned() == false) {
		std::cout << "Shrubbery form was not sighed yet!" << std::endl;
		throw ShrubberyCreationForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExec()) {
		std::cout << "Shrubbery creation failed!." << std::endl;
		throw ShrubberyCreationForm::GradeTooLowException();
	}
	std::ofstream output((this->getTarget() + "_shrubbery").c_str());
	if (!output.is_open()) {
		throw std::ios_base::failure("Failed to open the file");
	}
	output <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
	output.close();
}
std::string ShrubberyCreationForm::getTarget( void ) const {
	return this->_target;
}