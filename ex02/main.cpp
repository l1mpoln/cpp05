/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:41:06 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 06:22:43 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try 
    {
        Bureaucrat bob("Bob", 1);

        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("John Doe");
        PresidentialPardonForm pardonForm("Alice");

        bob.signForm(shrubberyForm);
        bob.signForm(robotomyForm);
        bob.signForm(pardonForm);

        bob.executeForm(shrubberyForm);
        bob.executeForm(robotomyForm);
        bob.executeForm(pardonForm);
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
