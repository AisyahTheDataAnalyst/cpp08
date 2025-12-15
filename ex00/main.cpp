/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:58:13 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/15 19:27:22 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*

	Containers in C++ STL (exists in C++98)
	`````````````````````
	
	1. Sequence Containers
	- implement data structures, accessed sequentially.
		> Vector				(resizable contiguous array)
		> Deque					(Dynamic array of fixed-size arrays that allows fast insertions and deletions at both ends.)
		> List					(doubly linked list)
		
	3. Container Adapters		
	- provide adapters / different interface for sequential containers.
		> Stack					(adapts a container to provide stack (LIFO data structure))
		> Queue					(adapts a container to provide queue (FIFO data structure))
		> Priority Queue		(adapts a container to provide priority queue)

	2. Associative Containers	
	- (All these existed in the Standard Template Library long before C++98.)
	- implement sorted data structures that can be quickly searched (O(log n) complexity).
		> Set					(collection of unique keys, sorted by keys)
		> Map					(collection of key-value pairs, sorted by keys, keys are unique)
		> Multiset				(collection of keys, sorted by keys)
		> Multimap				(collection of key-value pairs, sorted by keys)
	
	4. Unordered Associative Containers (C++11)
		
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
	// === Sequence containers ===
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
	testing<std::multiset<int> >();

	// cant test on map/multimap -> they need 2 arguments: key and value
	// border("TEST1 - std::map of int", PURPLE);
	// testing<std::map<int> >();
	
	// border("TEST2 - std::multimap of int", PURPLE);
	// testing<std::multimap<int> >();

	
	// === Container Adapters ===
	// -> cant test on them, they dont have .begin() / .end()

	return 0;
}