#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>
# include <stdexcept>
# include <limits>

class Span {
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

	Span();

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	template <typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end) {
		std::size_t count = std::distance(begin, end);
		if (_numbers.size() + count > _maxSize)
			throw FullContainerException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	class FullContainerException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Span container is full";
		}
	};

	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Not enough elements to calculate span";
		}
	};
};

#endif
