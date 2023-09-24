/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:39:28 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 05:52:56 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;
public:
    ShrubberyCreationForm(std::string target);
    virtual ~ShrubberyCreationForm();

    virtual void execute(const Bureaucrat& executor) const;

    class FileOpenException : public std::exception 
    {
        virtual const char* what() const throw();
    };
};

#endif
