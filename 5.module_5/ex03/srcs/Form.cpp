#include "../includes/Form.Class.hpp"
#include "../includes/Bureaucrat.Class.hpp"

Form::Form(const std::string &name) :
	gradeSign(1), gradeExec(1), name(name), isSigned(false)
{
	std::cout << name << " called form name only constructor" << std::endl;
}

Form::Form(const std::string &name, const int gradeSign, const int gradeExec) :
	isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec), name(name)
{
	std::cout << name << " called form full constructor" << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) :
	isSigned(src.isSigned), gradeSign(src.gradeSign), gradeExec(src.gradeExec), name(src.name)
{
	std::cout << name << " called form copy constructor" << std::endl;
}

Form::~Form(void)
{
	std::cout << name << " called form destructor" << std::endl;
}

Form::Form(void) :
	isSigned(false), gradeSign(1), gradeExec(1), name("default form")
{
	std::cout << name << " called form default constructor" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << name << " called form assignation operator" << std::endl;
	if (this == &rhs)
		return (*this);
	this->isSigned = rhs.getIsSigned();
	this->gradeSign = rhs.getGradeSign();
	this->gradeExec = rhs.getGradeExec();
	this->name = rhs.getName();
	return (*this);
}

const bool  Form::getIsSigned(void) const
{
	return (this->isSigned);
}

const int	Form::getGradeSign(void) const
{
	return (this->gradeSign);
}

const int	Form::getGradeExec(void) const
{
	return (this->gradeExec);
}

const std::string	&Form::getName(void) const
{
	return (this->name);
}

void	Form::beSigned(const Bureaucrat &Manager)
{
	if (!this->isSigned)
	{
		if (Manager.getGrade() <= this->gradeSign)
			this->isSigned = true;
		else
			throw Form::GradeTooLowException();
	}
	else
		throw Form::IsAlreadySignedException();
}

void Form::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
	std::cout << "Form " << rhs.getName() << " :" << std::endl;
	std::cout << "signed: " << rhs.getIsSigned() << ", grade to sign: " << rhs.getGradeSign();
	std::cout << ", grade to execute: " << rhs.getGradeExec() << std::endl;
	return (out);
}

