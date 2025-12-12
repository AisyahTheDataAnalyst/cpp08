/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:46:55 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/12 12:45:26 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

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

// HEADERS
# include <algorithm>	// std::find
# include <iostream>	// std::cerr, std::cout 
// 		sequence containers
# include <vector>		// std::vector
# include <list>		// std::list
# include <deque>		// std::deque
//		container adapters
# include <stack>		// std::stack
# include <queue>		// std::queue, std::priority_queue
//		associative containers
# include <map>			// std::map, std::multimap
# include <set>			// std::set, std::multiset

template <typename ContainerT>
typename ContainerT::iterator easyfind(ContainerT &container, const int &num)
{
	return std::find(container.begin(), container.end(), num);
}

template<typename ContainerT>
void testing()
{
	int arr[] = {26, 30, 34, 38, 42, 45, 69, 70, 5, 5, 3};
	ContainerT container(arr, arr + sizeof(arr)/sizeof(int));
	
	for (typename ContainerT::iterator it = container.begin();
		 it != container.end();
		 ++it)
	{
		const int &element = *it;
		std::cout << element << " at " << &element << '\n';
	}

	typename ContainerT::iterator it;
	
	it = easyfind(container, 26);
	std::cout << GREEN << "Found 26 at " << &(*it) << '\n' << RESET;

	it = easyfind(container, 0);
	if (it == container.end())
		std::cerr << RED <<"Cannot find 0, its the end() iterator instead\n" << RESET;
	
}

#endif