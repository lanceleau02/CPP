/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:46:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/30 11:15:54 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/stat.h>

static bool	isDirectory(const char *path) {
	struct stat	info;
	if (stat(path, &info) != 0)
		return false;
	return S_ISDIR(info.st_mode);
}

static void	sedIsForLosers(char **argv) {
	std::ifstream	sourceFile;
	std::ofstream	destinationFile;
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	char			buffer[s1.size() + 1];
	
	std::memset(buffer, 0, s1.size() + 1);
	sourceFile.rdbuf()->pubsetbuf(buffer, s1.size() + 1);
	try {
		sourceFile.open(argv[1]);
		if (isDirectory(argv[1]) == true || sourceFile.is_open() == false)
			throw std::runtime_error("Impossible to open the source file!");
		destinationFile.open(((std::string(argv[1])) + ".replace").c_str());
		if (destinationFile.is_open() == false)
			throw std::runtime_error("Impossible to open the destination file!");
	}
	catch (const std::runtime_error &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return ;
	}
	sourceFile.peek();
	while (!sourceFile.fail() && !sourceFile.eof()) {
		if (buffer == s1) {
			destinationFile << s2;
			sourceFile.seekg(s1.size(), std::ios_base::cur);
		} else {
			destinationFile << (char)sourceFile.peek();
			sourceFile.seekg(1, std::ios_base::cur);
		}
		sourceFile.peek();
	}
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error: wrong number of parameters." << std::endl;
		return 1;
	}
	sedIsForLosers(argv);
	return 0;
}