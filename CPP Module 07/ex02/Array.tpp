/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:13:32 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/26 15:56:01 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _array(new T()), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
	for (unsigned int i = 0; i < _size; i++)
			_array[i] = T();
}

template <typename T>
Array<T>::Array(const Array& source) : _array(new T[source._size]), _size(source._size) {
	*this = source;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& source) {
	if (this != &source) {
		delete[] _array;
		_array = new T[source._size];
		for (unsigned int i = 0; i < source._size; i++)
			_array[i] = source._array[i];
		_size = source._size;
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](unsigned int idx) {
	if (idx >= _size)
		throw Array<T>::IndexIsOutOfBoundsException();
	return _array[idx];
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
unsigned int	Array<T>::size() const {
	return _size;
}

template <typename T>
const char*	Array<T>::IndexIsOutOfBoundsException::what() const throw() {
	return ("Index is out of bounds!");
}

#endif