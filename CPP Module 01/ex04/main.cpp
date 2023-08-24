/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:46:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/23 16:47:23 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv) {
	if (argc == 1 || argc > 4) {
		std::cout << "Error: wrong number of parameters." << std::endl;
		return 1;
	}
	
	std::ifstream	sourceFile(argv[1]);
	std::ofstream	destinationFile((std::string(argv[1]) + ".replace").c_str());
	std::string		s1;
	std::string		s2;
	std::string		line;
	
	if (sourceFile.is_open() == false || destinationFile.is_open() == false) {
		std::cout << "Error: impossible to open a file!" << std::endl;
		return 1;
	}
	
	while (std::getline(sourceFile, line)) {
		
	}

	//destinationFile += ".replace";
	s1 = argv[2];
	s2 = argv[3];
	
	sourceFile.close();
	destinationFile.close();
}