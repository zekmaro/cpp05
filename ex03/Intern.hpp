/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:09:28 by anarama           #+#    #+#             */
/*   Updated: 2024/10/30 11:00:21 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <exception>
# include <string>

# include "AForm.hpp"

# define FORM_NAME_SHRUBBERY	"Schrubbery Creation"
# define FORM_NAME_ROBOTOMY		"Robotomy Request"
# define FORM_NAME_PRESIDENT	"Presidential Pardon"

class Intern {
	private:
		std::string _formNames[3];

	public:
		Intern( void );
		Intern( const Intern& other );
		Intern& operator=( const Intern& other );
		~Intern( void );

		class FormDoesntExistException : public std::exception {
			public:
				const char* what() const throw(); 	
		};

		void initFormNames( void );
		AForm* makeForm( std::string const& formName, std::string const& target) const;
};

#endif // INTERN_HPP