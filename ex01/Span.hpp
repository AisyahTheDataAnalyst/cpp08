/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:02:06 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/15 02:01:22 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define MYOWNTEST 1
#  define SMALLTEST 1
#  define BIGTEST 0
# define PDFTEST 0



// COLOURS
# define CYAN			"\033[1;36m"
# define PURPLE			"\033[1;35m"
# define BLUE			"\033[1;34m"
# define YELLOW			"\033[1;33m"
# define GREEN			"\033[1;32m"
# define RED			"\033[1;31m"
# define BLACK			"\033[1;30m"
# define WHITE			"\033[1;37m"
# define LIGHT_RED		"\033[0;91m"
# define LIGHT_GREEN	"\033[0;92m"
# define LIGHT_YELLOW	"\033[0;93m"
# define LIGHT_BLUE		"\033[0;94m"
# define LIGHT_MAGENTA	"\033[0;95m"
# define LIGHT_CYAN		"\033[0;96m"
# define GRAY			"\033[0;90m"
# define RESET			"\033[0m"
# define RL_CYAN		"\001\033[1;36m\002"
# define RL_COLOR		"\001\033[0m\002"

# include <climits>     // ULONG_MAX
# include <numeric>		// std::adjacent_difference
# include <cstdlib>		// std::srand, std::rand
# include <ctime>		// std::time
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
		size_t		_size;
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
		void addRange(itT begin, itT end);
		
		void addNumber(int n);
		size_t shortestSpan();
		size_t longestSpan();
		int &operator[](size_t index);

		
		// nested exception class
		class FullCapacityException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NoSpanFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

// void Span::addRange(vector<int>::iterator begin, vector<int>iterator end) 
// ->cant do this, thats why have to do templated function
template <typename itT>
void Span::addRange(itT begin, itT end)
{	
	if (this->_container.size() + std::distance(begin, end) > this->_size)
		throw FullCapacityException();

	this->_container.insert(this->_container.end(), begin, end);
}

#endif