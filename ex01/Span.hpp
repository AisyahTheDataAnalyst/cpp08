/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:02:06 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/12 19:41:06 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define SWITCH1 0
# define SWITCH2 1
# define TEST1 0
# define TEST2 0


# include <algorithm>	// std::find
# include <iterator>	// std::distance // Return value - The number of increments needed to go from first to last. , std::back_inserter
# include <iostream>	// std::cout, std::endl, std::cerr
// sequence containers
# include <vector>		// std::vector
# include <list>		// std::list
# include <deque>		// std::deque
// associative containers
# include <map>			// std::map, std::multimap
# include <set>			// std::set, std::multiset
// container adapters
# include <stack>		// std::stack
# include <queue>		// std::queue, std::priority_queue


class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_container;
		Span();
		
	public:
		// OCF
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		
		// methods
		template <typename itT>
		void addRangeNumber(itT begin, itT end);
		
		void addNumber(int n);
		size_t shortestSpan();
		size_t longestSpan();

		
		// nested exception class
		class FullCapacityException : std::exception
		{
			public:
				const char *what() const throw();
		};

		class NoSpanFoundException : std::exception
		{
			public:
				const char *what() const throw();
		};
};

template <typename itT>
void Span::addRangeNumber(itT begin, itT end)
{	
	if (!this->_container.size())
		throw std::runtime_error("Container's size is 0, cannot add elements");
	if (std::distance(begin, end) > this->_size)
		throw FullCapacityException();
		
	this->_container.clear();
	this->_container.resize(this->_size);
	for (it = this->_container.begin();
		 it != this->_container.end() && begin != end;
		 ++it && ++begin)
	{
		this->_container.push_back(*begin);
		if (this->_container.size() > this->_size)
			throw FullCapacityException();
	}
}

#endif