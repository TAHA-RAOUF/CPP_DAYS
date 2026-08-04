#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>

class RPN {
private:
    std::stack<long> _stack;

    bool isOperator(const std::string& token) const;
    long applyOperator(const std::string& op, long a, long b) const;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    bool evaluate(const std::string& expression, long& result);
};

#endif
