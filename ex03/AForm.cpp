/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:38:34 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 05:48:49 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
    _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false) 
    {
    if (gradeToSign < 1 || gradeToExecute < 1) 
    {
        throw AForm::GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) 
    {
        throw AForm::GradeTooLowException();
    }
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }
bool AForm::getSigned() const { return _signed; }

void AForm::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() 
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) 
{
    out << "Form " << form.getName() << " requires grade " << form.getGradeToSign() << " to sign and "
        << form.getGradeToExecute() << " to execute. Currently " << (form.getSigned() ? "signed" : "not signed");
    return out;
}
