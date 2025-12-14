/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:13:25 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/15 00:53:02 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// OCF

Span::Span() {} // privated

// if we put _container(N) -> wrong way in this exercise 
// vector will auto init all N elements to 0
// _container.size() will auto gives N even never push_back anything yet
// thus, push_back will start from the N+1 index
Span::Span(unsigned int N)
: _size(N), _container()
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
		this->_size = other._size;
		// 1 -> with resize
		this->_container.resize(other._size);
		std::copy(other._container.begin(), other._container.end(), this->_container.begin());
		// 2 -> w/o resize
		// std::copy(other._container.begin(), other._container.end(), std::back_inserter(this->_container));
	}
	return *this;
}

Span::~Span()
{
	this->_container.clear();
}



// methods

void Span::addNumber(int num)
{
	if (this->_container.size() >= this->_size)
		throw Span::FullCapacityException();

	this->_container.push_back(num);
}

/*
	example:
		_container 	= {3, 6, 1, 8};
		temp  		= {1, 3, 6, 8};  // (sorted)
		diffs 		= {1, (3-1), (6-3), (8-6)};
			 		= { 1, 2, 3, 2}; // thas why we search the shortest_span from index 1 (.begin() + 1)
*/
size_t Span::shortestSpan()
{
	if (this->_container.size() <= 1)
		throw Span::NoSpanFoundException();
	
		// WRONG WAY
	// std::sort(this->_container.begin(), this->_container.end());
	// int smallest = *(std::min_element(this->_container.begin(), this->_container.end()));
	// int secondSmallest = *(std::upper_bound(this->_container.begin(), this->_container.end(), smallest));
	// std::cout << "smallest= " << smallest << ", secondSmallest= " << secondSmallest << " \n";
	// size_t span = secondSmallest - smallest;
	// return span;
	
		// non-algo way:
	// size_t span = ULONG_MAX;
	// for (std::vector<int>::iterator it1 = _container.begin(); it1 != _container.end(); ++it1)
	// {
	// 	for (std::vector<int>::iterator it2 = _container.begin(); it2 != _container.end(); ++it2)
	// 	{
	// 		if (it1 != it2)
	// 		{
	// 			size_t diff = std::abs(*it1 - *it2);
	// 			if (span > diff)
	// 				span = diff;
	// 		}
	// 	}
	// }
	// return span;

	std::vector<int> temp = this->_container;
	std::vector<int> diffs(this->_size);
	std::sort(temp.begin(), temp.end());
	std::adjacent_difference(temp.begin(), temp.end(), diffs.begin());
	int smallest = *(std::min_element(diffs.begin() + 1, diffs.end()));
	return smallest;
}
		
size_t  Span::longestSpan()
{
	if (this->_container.size() <= 1)
		throw Span::NoSpanFoundException();
	
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
	// return span = largest - smallest;
	
	std::vector<int> temp = this->_container;
	std::sort(temp.begin(), temp.end());
	int smallest = *(std::min_element(temp.begin(), temp.end()));
	int largest = *(std::max_element(temp.begin(), temp.end()));
	size_t span = largest - smallest;
	return span;
}

int &Span::operator[](size_t index)
{
	// .at() throw their own std::out_of_range too
	if (index < 0 || index >= this->_container.size())
		throw std::out_of_range("Error: Out of bound!");
	
	return this->_container.at(index);
}

// exception class

const char *Span::FullCapacityException::what() const throw()
{
	return "Error: Number cannot be added because it has reached the maximum size for Span's container";
}


const char *Span::NoSpanFoundException::what() const throw()
{
	return "Error: Span's container's size is invalid to make span calculations";
}
