#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {
	_numbers.reserve(N);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize)
		throw FullContainerException();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() <= 1)
		throw NoSpanException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 0; i < sorted.size() - 1; ++i) {
		unsigned int diff = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() <= 1)
		throw NoSpanException();

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(maxVal - minVal);
}
