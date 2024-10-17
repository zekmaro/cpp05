/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:40:50 by anarama           #+#    #+#             */
/*   Updated: 2024/10/16 16:58:17 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <string>

# include "AForm.hpp"

# define DEFAULT_TARGET_SCHRUBBERY "default_shrubbery"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
		~ShrubberyCreationForm( void );

		void execute( Bureaucrat const& executor ) const;
		std::string getTarget( void ) const;
};

#endif // SHRUBBERY_CREATION_FORM_HPP