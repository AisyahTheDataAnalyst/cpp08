/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:56:29 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/15 02:00:52 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void border(const char *title, const char *colour)
{
	std::cout
	<< colour << "\n"
	<< "============================================================="
	<< "\n" << title  << "\n"
	<< "============================================================="
	<< RESET << std::endl;		

}

template <typename ContainerT>
void varietiesOfContainer(char const *subheader)
{
	std::cout << "\n========== " << subheader << " ==========\n";
	ContainerT temp(1000);
	// std::srand(std::time(NULL));
	
	// must put typename infront here coz compiler dosent know if it is a type/etc or not
	for (typename ContainerT::iterator it = temp.begin(); it != temp.end(); ++it)
		*it = std::rand();
	
	Span arr(1000);
	// arr.addNumber(1);  // will throw exception if both temp's & span's size is 1000
	arr.addRange(temp.begin(), temp.end());

	for (int i = 0; i < 1000; ++i)
		std::cout << "Number " << arr[i] << " at " << &arr[i] << ".\n";
	std::cout << "done!\n\n";
}

#if MYOWNTEST
// ==================================================================
// |                       my own tests								|
// ==================================================================
int main ()
{
	#if SMALLTEST
	{
		try 
		{
			border("Test0: AddNumber (0 size)", YELLOW);
			Span arr(0);
			arr.addNumber(9); // exception thrown
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n";
		}
	}
	{
		try 
		{
			border("Test1: AddNumber", YELLOW);
			unsigned int maxSize = 4;
			Span arr(maxSize);
			arr.addNumber(5);
			arr.addNumber(8);
			arr.addNumber(0);
			arr.addNumber(-1);
			// arr.addNumber(9); // exception thrown
			
			for (unsigned int i = 0; i < maxSize; ++i)
				std::cout << "Number " << arr[i] << " at " << &arr[i] << ".\n";
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n";
		}
	}
	{
		try
		{
			border("Test2: AddRange (small - int [])", YELLOW);
			int nums[] = {0,1,2,3,4,5,6,7,8,9};
			unsigned int maxSize = 15;
			std::vector<int> temp(nums, nums + 10);
			Span arr(maxSize);
			arr.addRange(temp.begin(), temp.end());

			for (unsigned int i = 0; i < maxSize; ++i)
				std::cout << "Number " << arr[i] << " at " << &arr[i] << ".\n";
			std::cout << "done!\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			border("Test3: Copy Constructor & Copy Assignment Operator", YELLOW);
			
			int nums[] = {9, 7, 5, 3, 1};
			int maxSize = sizeof(nums)/sizeof(int);
			std::vector<int> temp(nums, nums + maxSize);
			Span ori(maxSize);
			ori.addRange(temp.begin(), temp.end());
			std::cout << "\n---original---\n";
			for (int i = 0; i < maxSize; ++i)
				std::cout << ori[i] << " at " << &ori[i] << "\n";

			std::cout << "\n---copy constructor---\n";
			Span copy(ori);
			for (int i = 0; i < maxSize; ++i)
				std::cout << copy[i] << " at " << &copy[i] << "\n";

			std::cout << "\n---copy assignment constructor---\n";
			Span copyBoss(0);
			copyBoss = ori;
			for (int i = 0; i < maxSize; ++i)
				std::cout << copyBoss[i] << " at " << &copyBoss[i] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			border("Test4: shortestSpan & longestSpan", YELLOW);
			
			int nums[] = {9, 7, 5, 3, 1, 1};
			int maxSize = sizeof(nums)/sizeof(int);
			std::vector<int> temp(nums, nums + maxSize);
			Span ori(maxSize);
			ori.addRange(temp.begin(), temp.end());
			
			std::cout << "\n---values---\n";
			for (int i = 0; i < maxSize; ++i)
				std::cout << ori[i] << " at " << &ori[i] << "\n";
				
			std::cout 
			<< "\n---spans---\n"
			<< "shortestSpan = " << ori.shortestSpan() << "\n"
			<< "longestSpan  = " << ori.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	#endif
	#if BIGTEST
	{
		try
		{
			border("Test5: addRange (big - 1000)", YELLOW);

			varietiesOfContainer<std::list<int> >("Testing with list container");
			varietiesOfContainer<std::deque<int> >("Testing with deque container");
			varietiesOfContainer<std::vector<int> >("Testing with set container");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	#endif
	return 0;
}
#endif



#if PDFTEST
// ===========================================================================
// |				subject/evaluation sheet's given test                    |
// ===========================================================================
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

/*
Expected Output:
2
14
*/

#endif