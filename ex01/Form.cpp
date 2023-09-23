/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:28:12 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/23 07:35:54 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Form.cpp
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::~Form() {}

const std::string   &Form::getName() const { return _name; }
bool                Form::getSigned() const { return _signed; }
int                 Form::getGradeToSign() const { return _gradeToSign; }
int                 Form::getGradeToExecute() const { return _gradeToExecute; }

void                Form::beSigned(const Bureaucrat &bureaucrat) 
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form) 
{
    out << "Form " << form.getName() << " requires grade " << form.getGradeToSign() << " to sign and "
        << form.getGradeToExecute() << " to execute. Currently " << (form.getSigned() ? "signed" : "not signed");
    return out;
}
