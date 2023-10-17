/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:40:28 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 05:53:02 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    const std::string _target;
public:
    PresidentialPardonForm(std::string target);
    virtual ~PresidentialPardonForm();

    virtual void execute(const Bureaucrat& executor) const;

    class PardonException : public std::exception 
    {
        virtual const char* what() const throw();
    };
};

#endif
