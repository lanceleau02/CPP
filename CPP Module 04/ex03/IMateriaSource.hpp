/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:56:10 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/18 14:23:17 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

class IMateriaSource {
	public:
		virtual	~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif