/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:02:06 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/02 22:07:42 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>

class Span
{
	private:
		Span();
		// can store a maximum of N integers. N is an unsigned int
		
	public: //(not sure yet public/private)
		// OCF
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		
		// methods
		addNumber();
		shortestSpan();
		longestSpan();
		//  Implement a member function to add many numbers to your Span in one call.
};

#endif