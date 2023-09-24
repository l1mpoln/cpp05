/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:39:58 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 05:52:59 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    const std::string _target;
public:
    RobotomyRequestForm(std::string target);
    virtual ~RobotomyRequestForm();

    virtual void execute(const Bureaucrat& executor) const;

    class RobotomizeException : public std::exception 
    {
        virtual const char* what() const throw();
    };
};

#endif
