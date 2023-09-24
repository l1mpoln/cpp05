/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:38:14 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 05:53:10 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExecute;
    bool _signed;
public:
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    virtual ~AForm();

    const std::string& getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getSigned() const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0;

    class GradeTooHighException : public std::exception 
    {
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception 
    {
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
