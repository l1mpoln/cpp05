/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:25:09 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/23 07:34:29 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;
public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    ~Form();

    const std::string   &getName() const;
    bool                getSigned() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;

    void                beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
