/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:24:10 by anarama           #+#    #+#             */
/*   Updated: 2024/10/29 14:23:03 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

# define DEFAULT_FORM_NAME		"name"
# define DEFAULT_GRADE_TO_SIGN	1
# define DEFAULT_GRADE_TO_EXEC	1
# define DEFAULT_IS_SIGNED		false

class AForm {
	private:
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExec;
		bool				_isSigned;

	public:
		AForm( void );
		AForm( const AForm& other );
		AForm( std::string const name, int const gradeToSign,
				int const gradeToExec, bool isSigned);
		AForm& operator=( const AForm& other );
		virtual ~AForm( void );

		std::string const&	getName( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExec( void ) const;
		bool				getIsSigned( void ) const;

		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();	
		};

		class FormNotSignedException: public std::exception {
			public:
				const char* what() const throw();	
		};
		
		void setIsSigned( bool isSigned );
		
		void validateGradeForm( int grade );
		void beSigned( const Bureaucrat& b );

		virtual void execute( Bureaucrat const& executor ) const = 0;
};

std::ostream& operator<<( std::ostream& out, const AForm& other );

#endif // FORM_HPP