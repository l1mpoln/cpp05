/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:39:41 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 06:23:29 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
    AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
    if (!getSigned()) 
    {
        throw AForm::GradeTooLowException();
    }
    if (executor.getGrade() > getGradeToExecute()) 
    {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open()) 
    {
        throw ShrubberyCreationForm::FileOpenException();
    }

    file << "ASCII art of a tree" << std::endl;
    file.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() 
{
    return "Failed to open file for writing";
}
