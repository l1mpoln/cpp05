/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:01:18 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/23 02:46:00 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bur("Dima", 150);
        bur.incrementGrade();
        std::cout << bur << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}