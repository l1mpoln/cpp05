/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:40:10 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 05:49:41 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const 
{
    if (!getSigned()) 
    {
        throw AForm::GradeTooLowException();
    }
    if (executor.getGrade() > getGradeToExecute()) 
    {
        throw AForm::GradeTooLowException();
    }

    srand(time(0));
    int success = rand() % 2;
    if (success) 
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } 
    else 
    {
        throw RobotomyRequestForm::RobotomizeException();
    }
}

const char* RobotomyRequestForm::RobotomizeException::what() const throw() 
{
    return "Robotomy failed";
}
