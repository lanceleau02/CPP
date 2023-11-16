/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/16 14:50:21 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe(std::vector<int> X) {
	if (X.size() == 1)
		return X;

	std::vector<s_pair>	newX;
	std::vector<int>	toRepeat;
	std::vector<int>	S;
	s_pair				tmp;
	int i = 0;
	
	for (std::vector<int>::iterator it = X.begin(); it != X.end(); it += 2; i++) {
		if (*it > *(it + 1)) {
			tmp.min = *(it + 1);
			tmp.max = *it;
		} else {
			tmp.min = *it;
			tmp.max = *(it + 1);
		}
		newX.push_back(tmp);
		toRepeat.push_back(tmp.max);
		S = PmergeMe(toRepeat);
	}
	
	std::vector<int> copyS(S);
	
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++) {
		copyS.insert(copyS.begin() + pos, newX[pos2].min);
	}
}