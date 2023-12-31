/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:39:41 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/17 19:00:53 by vkuzmin          ###   ########.fr       */
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

    file << "            # #### ####\n"
    "        ### \\/#|### |/####\n"
    "        ##\\/#/ \\||/##/_/##/_#\n"
    "       ###  \\/###|/ \\/ # ###\n"
    "    ##_\\_#\\_\\## | #/###_/_####\n"
    "    ## #### # \\ #| /  #### ##/##\n"
    "    __#_--###`  |{,###---###-~\n"
    "                \\ }{\n"
    "                }}{\n"
    "                }}{\n"
    "            ejm  {{}\n"
    "        , -=-~{ .-^- _\n"
    "                `}\n"
    "                 {" << std::endl;
    file.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() 
{
    return "Failed to open file for writing";
}
