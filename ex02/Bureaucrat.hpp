/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:51:50 by anarama           #+#    #+#             */
/*   Updated: 2024/10/30 10:14:03 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>

# define DEFAULT_NAME "default_name"
# define DEFAULT_GRADE 150

class AForm;

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;
	
	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat( std::string const& name, int grade );
		Bureaucrat& operator=( const Bureaucrat& other );
		~Bureaucrat( void );

		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();	
		};

		std::string const& getName( void ) const;
		int getGrade( void ) const;

		void setGrade( int grade );

		void incrementGrade( void );
		void decrementGrade( void );

		void validateGrade( int grade ) const;
		void signForm( AForm & form );

		void executeForm( AForm const & form );
};

std::ostream& operator<<( std::ostream& out, const Bureaucrat&other );

#endif // BUREAUCRAT_HPP