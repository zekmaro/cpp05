/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:40:50 by anarama           #+#    #+#             */
/*   Updated: 2024/10/16 16:59:37 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <string>

# include "AForm.hpp"

# define DEFAULT_TARGET_PRESIDENT "default_president"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const& target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
		~PresidentialPardonForm( void );
		
		void execute( Bureaucrat const& executor ) const;
		std::string getTarget( void ) const;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP