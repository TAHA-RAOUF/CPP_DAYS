#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>

template <typename T>
class Array
{
private:
	T				*_elements;
	unsigned int	_size;

public:
	Array();
	Array(unsigned int n);
	Array(Array const &src);
	~Array();

	Array &operator=(Array const &rhs);

	T &operator[](unsigned int index);
	T const &operator[](unsigned int index) const;

	unsigned int size() const;

	class OutOfBoundsException : public std::exception
	{
	public:
		virtual char const *what() const throw();
	};
};

# include "Array.tpp"

#endif
