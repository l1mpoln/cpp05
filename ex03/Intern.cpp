/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 05:42:34 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/17 18:04:43 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {};

Intern::~Intern() {};

const char *Intern::UnknownFormException::what(void) const throw() {
    return "Unknown Form!!";
}

AForm    *Intern::makeForm(const std::string &name, const std::string &target) {
    std::string formNames[3] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };
    for (int i = 0; i < 3; i++) {
        if (name == formNames[i])
        {
            switch (i)
            {
            case 0:
                std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
                return new ShrubberyCreationForm(target);
            case 1:
                std::cout << "Intern creates RobotomyRequestForm" << std::endl;
                return new RobotomyRequestForm(target);
            case 2:
                std::cout << "Intern creates PresidentialPardonForm" << std::endl;
                return new PresidentialPardonForm(target);
            default:
                break;
            }
        }
    }
    throw Intern::UnknownFormException();
    return (NULL);
}