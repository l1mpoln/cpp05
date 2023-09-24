/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:40:53 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 05:49:19 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const 
{
    if (!getSigned()) 
    {
        throw AForm::GradeTooLowException();
    }
    if (executor.getGrade() > getGradeToExecute()) 
    {
        throw AForm::GradeTooLowException();
    }

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const char* PresidentialPardonForm::PardonException::what() const throw() 
{
    return "Pardon failed";
}
