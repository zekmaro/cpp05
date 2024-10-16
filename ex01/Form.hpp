/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:24:10 by anarama           #+#    #+#             */
/*   Updated: 2024/10/16 15:26:37 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
# include <string>

# define DEFAULT_FORM_NAME "name"
# define DEFAULT_GRADE_TO_SIGN 1
# define DEFAULT_GRADE_TO_EXEC 1
# define DEFAULT_IS_SIGNED false

class Form {
	private:
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExec;
		bool				_isSigned;

	public:
		Form( void );
		Form( const Form& other );
		Form& operator=( const Form& other );
		~Form( void );

		std::string const&	getName( void ) const;
		int const			getGradeToSign( void ) const;
		int const			getGradeToExec( void ) const;
		bool				getIsSigned( void ) const;

		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();	
		};
		
		bool setIsSigned( bool isSigned );
		
		void validateGradeForm( int grade );
		void beSigned( const Bureaucrat& b );
};

#endif // FORM_HPP