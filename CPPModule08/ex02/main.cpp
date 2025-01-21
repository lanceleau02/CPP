/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:10:00 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/01 14:06:37 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <vector>

#define UNDERLINE "\033[4m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

int	main() {
	std::cout << YELLOW << "+--------+ SUBJECT TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << UNDERLINE BLUE << "MutantStack type:" << NONE << std::endl;
		std::cout << std::endl;
		{
			MutantStack<int> mstack;
		
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
			
			MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();
			
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::stack<int> s(mstack);
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "std::list type:" << NONE << std::endl;
		std::cout << std::endl;
		{
			std::list<int> mstack;
		
			mstack.push_back(5);
			mstack.push_back(17);
			
			std::cout << mstack.back() << std::endl;
			
			mstack.pop_back();
			
			std::cout << mstack.size() << std::endl;
			
			mstack.push_back(3);
			mstack.push_back(5);
			mstack.push_back(737);
			//[...]
			mstack.push_back(0);
			
			std::list<int>::iterator it = mstack.begin();
			std::list<int>::iterator ite = mstack.end();
			
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::list<int> s(mstack);
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "std::vector type:" << NONE << std::endl;
		std::cout << std::endl;
		{
			std::vector<int> mstack;
		
			mstack.push_back(5);
			mstack.push_back(17);
			
			std::cout << mstack.back() << std::endl;
			
			mstack.pop_back();
			
			std::cout << mstack.size() << std::endl;
			
			mstack.push_back(3);
			mstack.push_back(5);
			mstack.push_back(737);
			//[...]
			mstack.push_back(0);
			
			std::vector<int>::iterator it = mstack.begin();
			std::vector<int>::iterator ite = mstack.end();
			
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::vector<int> s(mstack);
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "std::deque type:" << NONE << std::endl;
		std::cout << std::endl;
		{
			std::deque<int> mstack;
		
			mstack.push_back(5);
			mstack.push_back(17);
			
			std::cout << mstack.back() << std::endl;
			
			mstack.pop_back();
			
			std::cout << mstack.size() << std::endl;
			
			mstack.push_back(3);
			mstack.push_back(5);
			mstack.push_back(737);
			//[...]
			mstack.push_back(0);
			
			std::deque<int>::iterator it = mstack.begin();
			std::deque<int>::iterator ite = mstack.end();
			
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::deque<int> s(mstack);
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ DEEP COPY TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		MutantStack<int>			mstack1;
		MutantStack<int>			mstack2;
		std::deque<int>::iterator	it;
		std::deque<int>::iterator	ite;
		
		std::cout << "First, we create two MutantStack objects: mstack1 and mstack2." << std::endl << std::endl;
		std::cout << "Then, we add some random values to mstack1." << std::endl << std::endl;
		
		mstack1.push(42);
		mstack1.push(4515);
		mstack1.push(546);
		mstack1.push(5);
		mstack1.push(166155);
		
		std::cout << "Values in mstack1 before deep copy: ";
		it = mstack1.begin();
		ite = mstack1.end();
		while (it != ite)
			std::cout << *it++ << " ";
			
		std::cout << std::endl << std::endl;
		
		std::cout << "Values in mstack2 before deep copy: ";
		it = mstack2.begin();
		ite = mstack2.end();
		while (it != ite)
			std::cout << *it++ << " ";
		
		std::cout << std::endl << std::endl << "Now we do the deep copy: mstack2 = mstack1" << std::endl << std::endl;
		
		mstack2 = mstack1;
		
		std::cout << "Values in mstack1 after deep copy: ";
		it = mstack1.begin();
		ite = mstack1.end();
		while (it != ite)
			std::cout << *it++ << " ";
			
		std::cout << std::endl << std::endl;
		
		std::cout << "Values in mstack2 after deep copy: ";
		it = mstack2.begin();
		ite = mstack2.end();
		while (it != ite)
			std::cout << *it++ << " ";
		
		std::cout << std::endl << std::endl << "Now we delete the last element of mstack2 using pop() method." << std::endl << std::endl;
		
		mstack2.pop();
		
		std::cout << "Values in mstack1 after modifications: ";
		it = mstack1.begin();
		ite = mstack1.end();
		while (it != ite)
			std::cout << *it++ << " ";
			
		std::cout << std::endl << std::endl;
		
		std::cout << "Values in mstack2 after modifications: ";
		it = mstack2.begin();
		ite = mstack2.end();
		while (it != ite)
			std::cout << *it++ << " ";
		
		std::cout << std::endl;
	}
	return 0;
}