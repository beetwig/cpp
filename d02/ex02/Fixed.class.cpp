/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 10:54:07 by gleger            #+#    #+#             */
/*   Updated: 2015/01/07 21:33:16 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cmath>
#include <Fixed.class.hpp>

Fixed::Fixed()						:_rawBits (0), _fracBits(8)
{
	std::cout<<"Default constructor called"<<std::endl;
	Fixed::_nbFixed+=1;
	return;
}

Fixed::Fixed(int value)				:_fracBits(8)
{
	std::cout<<"Integer constructor called"<<std::endl;
	this->setRawBits(value*pow(2,this->_fracBits));
	Fixed::_nbFixed+=1;
	return;
}

Fixed::Fixed(float value)				:_fracBits(8)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->setRawBits(roundf(value*pow(2,this->_fracBits)));
	Fixed::_nbFixed+=1;
	return;
}

Fixed::Fixed(Fixed const & ref)		:_fracBits(8)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this=ref;
	Fixed::_nbFixed+=1;
	return;
}

Fixed::~Fixed()
{
	std::cout<<"Destroyed"<<std::endl;
	Fixed::_nbFixed-=1;
	return;
}

std::ostream &		operator<<(std::ostream & o, Fixed const & value)
{
	o << value.toFloat();
	return o;
}

Fixed &			Fixed::operator=(Fixed const & source)
{
	std::cout<<"Assignation operator called"<<std::endl;
	if (this != &source)
		this->_rawBits= source.getRawBits();

	return *this;
}

Fixed			Fixed::operator*(Fixed const & source) const
{
	return (Fixed (this->toFloat() * source.toFloat()));
}

Fixed			Fixed::operator+(Fixed const & source) const
{
	return (Fixed (this->toFloat() + source.toFloat()));
}

Fixed			Fixed::operator-(Fixed const & source) const
{
	return (Fixed (this->toFloat() - source.toFloat()));
}

Fixed			Fixed::operator/(Fixed const & source) const
{
	return (Fixed (this->toFloat() / source.toFloat()));
}

bool			Fixed::operator>(Fixed const & source) const
{
	return (this->toFloat() > source.toFloat());
}

bool			Fixed::operator<(Fixed const & source) const
{
	return (this->toFloat() < source.toFloat());
}

bool			Fixed::operator>=(Fixed const & source) const
{
	return (this->toFloat() >= source.toFloat());
}

bool			Fixed::operator<=(Fixed const & source) const
{
	return (this->toFloat() <= source.toFloat());
}

bool			Fixed::operator==(Fixed const & source) const
{
	return (this->toFloat() == source.toFloat());
}

bool			Fixed::operator!=(Fixed const & source) const
{
	return (this->toFloat() != source.toFloat());
}

int				Fixed::getRawBits(void) const
{
	//std::cout<<"getRawBits member function called"<<std::endl;
	return this->_rawBits;
}

void			Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float			Fixed::toFloat() const
{
	return (this->getRawBits()/pow(2,this->_fracBits));
}

int				Fixed::toInt() const
{
	return (this->getRawBits()/pow(2,this->_fracBits));
}

void			Fixed::printme() const
{
	std::cout<<"My fixed value is "<<this->_rawBits<<std::endl;
}

int					Fixed::getNbFixed(void)
{
	return Fixed::_nbFixed;
}

const Fixed &		Fixed::min(const Fixed & val1, const Fixed & val2)
{
	if (val1 >= val2)
		return val2;
	return val1;
}

Fixed &				Fixed::min(Fixed & val1, Fixed & val2)
{
	if (val1 >= val2)
		return val2;
	return val1;
}

const Fixed &		Fixed::max(const Fixed & val1, const Fixed & val2)
{
	if (val1 >= val2)
		return val1;
	return val2;
}

Fixed &				Fixed::max(Fixed & val1, Fixed & val2)
{
	if (val1 >= val2)
		return val1;
	return val2;
}

int				Fixed::_nbFixed = 0;
