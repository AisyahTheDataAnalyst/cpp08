/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:52:47 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/15 17:32:17 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void border(const char *title, const char *colour)
{
	std::cout
	<< colour << "\n"
	<< "============================================================="
	<< "\n" << title  << "\n"
	<< "============================================================="
	<< RESET << std::endl;		

}


#if MYOWNTEST
// ==================================================================
// |                       my own tests								|
// ==================================================================
int main ()
{
	border("Test1: Iterators & Copying", YELLOW);
	
	// original
	std::cout << GREEN << "===ori===\n";
	MutantStack<int> ori;
	ori.push(3);
	ori.push(6);
	ori.push(9);
	
	MutantStack<int>::iterator itB = ori.begin();
	MutantStack<int>::iterator itE = ori.end();
	MutantStack<int>::reverse_iterator itRB = ori.rbegin();
	MutantStack<int>::reverse_iterator itRE = ori.rend();
	
	std::cout << "ori size = " << ori.size() << "\n";
	std::cout << "iterating forward...\n";
	for(; itB != itE; ++itB)
		std::cout << *itB << " , ";
	std::cout << "end!\n";
	
	std::cout << "reverse iterating...\n";
	for(; itRB != itRE; ++itRB)
		std::cout << *itRB << " , ";
	std::cout << "end!\n" << RESET << std::endl;

	// copy constructor
	std::cout << BLUE << "===copy constructor===\n";
	MutantStack<int> copy(ori);
	
	itB = copy.begin();
	itE = copy.end();
	itRB = copy.rbegin();
	itRE = copy.rend();
	
	std::cout << "copy size = " << copy.size() << "\n";
	std::cout << "iterating forward...\n";
	for(; itB != itE; ++itB)
		std::cout << *itB << " , ";
	std::cout << "end!\n";
	
	std::cout << "reverse iterating...\n";
	for(; itRB != itRE; ++itRB)
		std::cout << *itRB << " , ";
	std::cout << "end!\n" << RESET << std::endl;	
	

	// copy assignment operator
	std::cout << PURPLE << "===copy assignment operator===\n";
	MutantStack<int> copyBoss;
	copyBoss.push(8);
	copyBoss.push(8);
	copyBoss.push(8);
	copyBoss.push(3);
	copyBoss.push(3);
	
	std::cout << "BEFORE COPY ASSIGNMENT OPERATER\n";
	
	itB = copyBoss.begin();
	itE = copyBoss.end();
	itRB = copyBoss.rbegin();
	itRE = copyBoss.rend();

	std::cout << "copyBoss size = " << copyBoss.size() << "\n";
	std::cout << "iterating forward...\n";
	for(; itB != itE; ++itB)
		std::cout << *itB << " , ";
	std::cout << "end!\n";
	
	std::cout << "reverse iterating...\n";
	for(; itRB != itRE; ++itRB)
		std::cout << *itRB << " , ";
	std::cout << "end!\n" << std::endl;	
	
	copyBoss = ori;
	
	std::cout << "AFTER COPY ASSIGNMENT OPERATER\n";
	
	itB = copyBoss.begin();
	itE = copyBoss.end();
	itRB = copyBoss.rbegin();
	itRE = copyBoss.rend();
	
	std::cout << "copyBoss size = " << copyBoss.size() << "\n";
	std::cout << "iterating forward...\n";
	for(; itB != itE; ++itB)
		std::cout << *itB << " , ";
	std::cout << "end!\n";
	
	std::cout << "reverse iterating...\n";
	for(; itRB != itRE; ++itRB)
		std::cout << *itRB << " , ";
	std::cout << "end!\n" << RESET << std::endl;	
}
#endif



#if PDFTEST
// ===========================================================================
// |				subject/evaluation sheet's given test                    |
// ===========================================================================

// Cant default it to std::deque for templated function (C++11)
// can only default to templated class in C++98
template <class ContainerT>
void MutantStackTest()
{
	MutantStack<int, ContainerT> mstack;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	typename MutantStack<int, ContainerT>::iterator it = mstack.begin();
	typename MutantStack<int, ContainerT>::iterator ite = mstack.end();
	
	++it;
	--it;
	std::cout << "\nfinal :\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int, ContainerT> copy(mstack);
	
	std::cout 
	<< "\n---size comparison---\n"
	<< "MutantStack = " << mstack.size() << "\n"
	<< "copy        = " << copy.size() << std::endl;
}

template <typename ContainerT>
void containersTest()
{
	ContainerT c;
	
	c.push_back(5);
	c.push_back(17);
	std::cout << c.back() << std::endl;
	c.pop_back();
	std::cout << c.size() << std::endl;
	
	c.push_back(3);
	c.push_back(5);
	c.push_back(737);
	//[...]
	c.push_back(0);
	
	typename ContainerT::iterator it = c.begin();
	typename ContainerT::iterator ite = c.end();
	
	++it;
	--it;
	std::cout << "\nfinal :\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	ContainerT copy(c);
	
	std::cout 
	<< "\n---size comparison---\n"
	<< "c    = " << c.size() << "\n"
	<< "copy = " << copy.size() << "\n"
	<< "\n---copy constructor---\n";
	it = copy.begin();
	ite = copy.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	border("Test on our own MutantStack class - std::deque (default)", YELLOW);
	MutantStackTest<std::deque<int> >();
	border("Test on our own MutantStack class - std::vector", YELLOW);
	MutantStackTest<std::vector<int> >();
	border("Test on our own MutantStack class - std::list", YELLOW);
	MutantStackTest<std::list<int> >();
	border("Test on std::deque", PURPLE);
	containersTest<std::deque<int> >();
	border("Test on std::vector", PURPLE);
	containersTest<std::vector<int> >();
	border("Test on std::list", PURPLE);
	containersTest<std::list<int> >();
	return 0;
}
#endif