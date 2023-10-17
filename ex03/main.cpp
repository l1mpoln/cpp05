/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:41:06 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/17 18:17:06 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try 
    {
        Intern intern;
        AForm *form1 = intern.makeForm("ShrubberyCreationForm", "form");
        AForm *form2 = intern.makeForm("RobotomyRequestForm", "John Doe");
        AForm *form3 = intern.makeForm("PresidentialPardonForm", "Alice");

        Bureaucrat bob("Bob", 1);

        bob.signForm(*form1);
        bob.signForm(*form2);
        bob.signForm(*form3);

        bob.executeForm(*form1);
        bob.executeForm(*form2);
        bob.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
