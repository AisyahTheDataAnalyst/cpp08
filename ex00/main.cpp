/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:58:13 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/04 12:54:33 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*

	Containers in C++ STL (exists in C++98)
	`````````````````````
	
	1. Sequence Containers
		- Vector				(auto resizable dynamic array)
		- Deque					(Dynamic array of fixed-size arrays that allows fast insertions and deletions at both ends.)
		- List					(doubly linked list)
		
	3. Container Adapters		(These are adapters around existing containers (vector, deque, list))
		- Stack
		- Queue
		- Priority Queue

	2. Associative Containers	(All these existed in the Standard Template Library long before C++98.)
		- Set
		- Map
		- Multiset
		- Multimap
		
		
*/



// ==================================================================
// |                       my own tests								|
// ==================================================================

void borderUltra(const char *title, const char *colour)
{
	std::cout
	<< colour << "\n"
	<< "============================================================="
	<< "\n\t\t\t"<< title  << "\n"
	<< "============================================================="
	<< RESET << std::endl;		
}

void border(const char *title, const char *colour)
{
	std::cout << "\n" << colour << title << RESET << std::endl;		
}

int main()
{
	// Sequence containers
	borderUltra("Sequence Containers", YELLOW);
	
	border("TEST1 - std::vector of int", YELLOW);
	testing<std::vector<int> >();

	border("TEST2 - std::deque of int", YELLOW);
	testing<std::deque<int> >();

	border("TEST3 - std::list of int", YELLOW);
	testing<std::list<int> >();


	
	// The only associative containers we can test on
	borderUltra("Associative Containers", PURPLE);
	
	border("TEST1 - std::set of int", PURPLE);
	testing<std::set<int> >();
	
	border("TEST2 - std::multiset of int", PURPLE);
	testing<std::set<int> >();

	// cant test on them -> they need 2 arguments: key and value
	// border("TEST1 - std::map of int", PURPLE);
	// testing<std::map<int> >();
	
	// border("TEST2 - std::multimap of int", PURPLE);
	// testing<std::multimap<int> >();

	
	// Container Adapters
	// -> cant test on them, they need additional arguments
	// borderUltra("Container Adapters", PURPLE);
	
	// border("TEST1 - std::stack of int", BLUE);
	// testing<std::stack<int> >();

	// border("TEST2 - std::queue of int", BLUE);
	// testing<std::queue<int> >();

	// border("TEST3 - std::priority_queue of int", BLUE);
	// testing<std::priority_queue<int> >();


	return 0;
}