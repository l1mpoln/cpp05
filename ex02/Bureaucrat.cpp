/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <zxcmasterass@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:01:49 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/09/24 06:20:00 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"

void Bureaucrat::executeForm(const AForm& form) 
{
    try 
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << _name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) 
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const 
{
    return _name;
}

int Bureaucrat::getGrade() const 
{
    return _grade;
}

void Bureaucrat::incrementGrade() 
{
    if (_grade > 1)
        _grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (_grade < 150)
        _grade++;
}

void Bureaucrat::signForm(AForm &form) 
{
    try 
    {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) 
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
