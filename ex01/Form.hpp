/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:24:10 by anarama           #+#    #+#             */
/*   Updated: 2024/10/16 12:39:03 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

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

		bool setIsSigned( bool isSigned );
		
		void validateGrade( int grade );
};

#endif // FORM_HPP