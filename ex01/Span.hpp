/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:02:06 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/04 20:47:19 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define SWITCH1 0
# define SWITCH2 1
# define TEST1 0
# define TEST2 0


# include <algorithm>	// std::find
# include <iostream>	// std::cout, std::endl, std::cerr
# include <iterator>	// std::distance
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

template <typename ContainerT>
class Span
{
	private:
		size_t		_size;
		ContainerT	container(_size);
		Span();
		
	public:
		// OCF
		Span(size_t N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		
		// methods
		void addNumber(unsigned int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addRangeNumber(ContainerT::iterator begin, Container::iterator end);

		
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


# if SWITCH1
# include "Span.tpp"
# endif


# if SWITCH2
// OCF

Span::Span() {} // privated

template <typename T>
Span::Span(unsigned int N)
: _size(N), container(N)
{}

template <typename T>
Span::Span(const Span &other)
{
	*this = other;
}

template <typename T>
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		delete [] this->container;
		this->_size = other._size;
		this->container(other.size);
	}
}

template <typename ContainerT>
Span::~Span()
{
	delete [] container;
}

// methods

template <typename ContainerT>
void addNumber(unsigned int num)
{
	typename ContainerT::iterator container.begin() begin;
	typename ContainerT::iterator container.end() end;
	
	for (; begin != end; ++begin)
	{
		if (!begin)
		{
			container[begin] = num;
			break;
		}		
	}
}

template <typename ContainerT>
void addRangeNumber(ContainerT::interator begin, ContainerT::iterator end)
{
	
	
	for (; typename container.begin() it != container.end(); ++it && ++begin)
	{
		if (!it)
			container[] = begin;
	}
}


# endif

#endif