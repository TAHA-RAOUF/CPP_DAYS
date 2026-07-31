#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n)
{
	if (_size > 0)
		_elements = new T[_size]();
}

template <typename T>
Array<T>::Array(Array const &src) : _elements(NULL), _size(0)
{
	*this = src;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		delete[] _elements;
		_size = rhs._size;
		if (_size > 0)
		{
			_elements = new T[_size]();
			for (unsigned int i = 0; i < _size; ++i)
				_elements[i] = rhs._elements[i];
		}
		else
		{
			_elements = NULL;
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
char const *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index out of bounds";
}

#endif
