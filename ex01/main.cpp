/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:01:18 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 00:06:11 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    Bureaucrat bob("Bob", 10);
    Form taxForm("Tax Form", 5, 5);

    bob.signForm(taxForm);

    Bureaucrat alice("Alice", 2);
    alice.signForm(taxForm);
    
    return 0;
}
