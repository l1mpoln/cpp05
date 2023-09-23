/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:28:19 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/23 03:29:50 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;
    
public:
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
    
    Bureaucrat( const std::string& name, int grade );
    ~Bureaucrat();

    std::string getName() const;
    int         getGrade() const;

    void        incrementGrade();
    void        decrementGrade();
};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif 