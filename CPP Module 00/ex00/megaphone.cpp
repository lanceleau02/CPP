/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:14:48 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/27 15:57:38 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	megaphone(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; argv[i]; i++) {
			for (int j = 0; argv[i][j]; j++) {
				if (std::islower(argv[i][j]) != 0) {
					char c = std::toupper(argv[i][j]);
					std::cout << c;
				}
				else
					std::cout << argv[i][j];
			}
		}
	}
}

int	main(int argc, char **argv) {
	megaphone(argc, argv);
}
