/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:00:51 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/15 18:04:44 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define MYOWNTEST 0
# define PDFTEST 1

# include <vector>		// std::vector
# include <list>		// std::list
# include <deque>		// std::deque
# include <stack>		// std::stack
# include <algorithm>	// std::copy
# include <iostream>	// std::cout, std::cerr

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

/*
	The std::stack class is a container adaptor 
	that gives the programmer the functionality of a stack 
	- specifically, a LIFO (last-in, first-out) data structure.

	The type of the underlying container to use to store the elements. 
	The container must satisfy the requirements of SequenceContainer. 
	Additionally, it must provide the following functions with the usual semantics:
		back(), e.g., std::vector::back(),
		push_back(), e.g., std::deque::push_back(),
		pop_back(), e.g., std::list::pop_back().
	The standard containers 
	- std::vector (including std::vector<bool>), 
	- std::deque and 
	- std::list 
	satisfy these requirements. 
	By default, std::deque is used if no container class is specified
*/


// even though std::stack has specify deque as the default in their template arg
// C++ never inherits default template arguments from another template.
// WRONG -> template <class T, class Container>
template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> // container inheritance - no virtal destructor so.. not safe for long inheritence
{	
	
	// no need this protected part, already apart form the template headline itself
	// or else itll look like 
	// - shadow the base class member
	// - break the relationship with std::stack
	// 
	// protected:
	// 	Container c;
	
	public:
		//OCF
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack(); 
		
		// iterators
		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
};


// a default template argument cannot be specified
// on the definition on the class template member outside the template 
// WRONG ==>  template <class T, class Container = std::deque<T> >

template <class T, class Container>
MutantStack<T, Container>::MutantStack() {}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other)
{
	*this = other;
}

template <class T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &other)
{
	if (this != other)
	{
		// this is unnecessary, containers will handle it themselves
		// if (this->c.empty())
		// 	this->c.clear();
		// this->c.resize(other.c.size());
		// std::copy(other.c.begin(), other.c.end(), this->c.begin());

		// this alone is enough as a complete deep copy
		this->c = other.c;
	}
	return *this;
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack()
{
	// this->c.clear(); // container's destructors already handle freeing memory 
}

// compiler dosent know what iterator is(static/ type/ etc ?)
template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return this->c.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return this->c.rend();
}

#endif