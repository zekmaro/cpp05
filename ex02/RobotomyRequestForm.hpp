/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:40:50 by anarama           #+#    #+#             */
/*   Updated: 2024/10/16 16:59:44 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <string>

# include "AForm.hpp"

# define DEFAULT_TARGET_ROBOTOMY "default_robotomy"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const& target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
		~RobotomyRequestForm( void );

		void execute( Bureaucrat const& executor ) const;
		std::string getTarget( void ) const;
};

#endif // ROBOTOMY_REQUEST_FORM_HPP