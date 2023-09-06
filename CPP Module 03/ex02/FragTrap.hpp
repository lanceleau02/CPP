/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:30:28 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/04 13:38:27 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& source);
		FragTrap&	operator=(const FragTrap& source);
		~FragTrap();
		
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif