/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:52:48 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/18 14:10:35 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

class Ice : public AMateria {
	private:
	
	public:
		Ice();
		Ice(const Ice& source);
		Ice&	operator=(const Ice& source);
		~Ice();
		
		virtual AMateria*	clone() const;
};

#endif