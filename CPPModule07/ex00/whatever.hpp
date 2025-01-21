/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:37:03 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/19 13:49:46 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T&	min(const T& a, const T& b) {
	return (a < b) ? a : b;
}

template <typename T>
const T&	max(const T& a, const T& b) {
	return (a > b) ? a : b;
}

#endif