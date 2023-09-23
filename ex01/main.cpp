/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:01:18 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/23 07:41:47 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try 
    {
        Bureaucrat bob("Bob", 10);
        std::cout << bob << std::endl;

        Form taxForm("Tax Form", 5, 5);
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat alice("Alice", 2);
        std::cout << alice << std::endl;

        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        // Attempt to create bureaucrats with invalid grades
        try 
        {
            Bureaucrat invalid("Invalid", 151);
        } 
        catch (Bureaucrat::GradeTooLowException &e) 
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // Attempt to sign a form with too low grade
        try 
        {
            Form invalidForm("Invalid Form", 1, 1);
            invalidForm.beSigned(bob);
        } 
        catch (Form::GradeTooLowException &e) 
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    } 
    catch (Bureaucrat::GradeTooHighException &e) 
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    } 
    catch (Bureaucrat::GradeTooLowException &e) 
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
