/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:13:25 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/04 19:55:50 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
# define SPAN_TPP





// methods
template <typename ContainerT>
void Span::addNumbers(unsigned int num)
{
	typename container.begin()	begin;
	typename container.end()	end;
	
	for (; begin != end; ++begin)
	{
		if (!begin)
		{
			container[begin] = num;
			break ;
		}
	}
}

template <typename ContainerT>
unsigned int Span::shortestSpan(ContainerT &container)
{
	if (!container.size() || container.size() == 1)
		throw NoSpanFoundException();
	
}

template <typename ContainerT>
unsigned int Span::longestSpan(ContainerT &container)
{
	if (!container.size() || container.size() == 1)
		throw NoSpanFoundException();	
}





#endif