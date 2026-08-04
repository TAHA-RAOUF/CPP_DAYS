#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

long RPN::applyOperator(const std::string& op, long a, long b) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    return 0;
}

bool RPN::evaluate(const std::string& expression, long& result) {
    while (!_stack.empty()) _stack.pop();

    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() == 1 && std::isdigit(token[0])) {
            _stack.push(token[0] - '0');
        } else if (isOperator(token)) {
            if (_stack.size() < 2)
                return false;
            long b = _stack.top(); _stack.pop();
            long a = _stack.top(); _stack.pop();
            try {
                long res = applyOperator(token, a, b);
                _stack.push(res);
            } catch (const std::exception&) {
                return false;
            }
        } else {
            return false;
        }
    }

    if (_stack.size() != 1)
        return false;

    result = _stack.top();
    return true;
}
