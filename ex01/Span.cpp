/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:13:25 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/12 20:05:00 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// OCF

Span::Span() {} // privated

Span::Span(unsigned int N)
: _size(N), _container(N) // vector will auto init all N elements to 0
{}


Span::Span(const Span &other)
{
	*this = other;
}


Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		if (!this->_container.empty())
			this->_container.clear();
		this->_size = other._container.size();
		// this->_container.resize(other._container.size());
		// std::copy(other._container.begin(), other._container.end(), this->_container.begin());
		std::copy(other._container.begin(), other._container.end(), std::back_inserter(this->_container));
	}
}

Span::~Span()
{
	this->_container.clear();
}

// methods


void Span::addNumber(int num)
{
	if (!this->_container.size())
		throw std::runtime_error("Container's size is 0, cannot add elements");
	// if (std::distance(this->_container.begin(), this->_container.end()) >= this->_size)
	// 	throw FullCapacityException();

	this->_container.push_back(num);

	if (this->_container.size() > this->_size)
		throw FullCapacityException();
}

size_t Span::shortestSpan()
{
	if (_container.size() <= 1)
		throw NoSpanFoundException();
	
	std::sort(this->_container.begin(), this->_container.end());
	int smallest = *(std::min_element(this->_container.begin(), this->_container.end()));
	int secondSmallest = *(std::lower_bound(this->_container.begin(), this->_container.end(), smallest));
	size_t span = secondSmallest - smallest;
	return span;
}
		
size_t  Span::longestSpan()
{
	if (this->_container.size() <= 1)
		throw NoSpanFoundException();
	
	// the non-algorithm way:
	// unsigned int smallest = *_container.begin();
	// unsigned int largest = *_container.begin();
	// size_t span;
	// for (it = _container.begin(); it != _container.end(); ++it)
	// {
	// 	if (smallest > *it)
	// 		smallest = *it;
	// 	if (largest < *it)
	// 		largest = *it;
	// }
	// span = largest - smallest;
	
	std::sort(this->_container.begin(), this->_container.end());
	int smallest = *(std::min_element(this->_container.begin(), this->_container.end()));
	int largest = *(std::max_element(this->_container.begin(), this->_container.end()));
	size_t span = largest - smallest;
	return span;
}


// exception class

const char *Span::FullCapacityException::what () const throw()
{
	return "Number cannot be added becuase it has reached the maximum size for Span's container";
}


const char *Span::NoSpanFoundException::what () const throw()
{
	return "Span's container's size is invalid to make span calculations";
}
