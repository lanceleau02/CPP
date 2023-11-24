/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:53 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/24 10:18:28 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>

void	PmergeMe(char **argv);

template <typename Container>
typename Container::iterator	binarySearch(Container& A, int L, int R, int T) {	
	while (L <= R) {
		int m = floor((L + R) / 2);
		if (A[m] < T)
			L = m + 1;
		else if (A[m] > T)
			R = m - 1;
		else
			return A.begin() + m;
	}
	typename Container::iterator it = A.begin();
	std::advance(it, L);
	return it;
}

template <typename Container>
typename Container::iterator findElement(Container& pairs, typename Container::value_type::first_type target) {
    for (typename Container::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it->first == target)
            return it;
    }
    return pairs.end();
}

#endif