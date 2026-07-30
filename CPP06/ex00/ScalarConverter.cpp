#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" ||
            str == "inf" || str == "inff" ||
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff");
}

static void printPseudo(const std::string& str) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nan" || str == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (str == "-inf" || str == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } else if (str == "+inf" || str == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
}

static void formatAndPrintFloat(float f) {
    std::stringstream ss;
    ss << f;
    std::string s = ss.str();
    if (s.find('.') == std::string::npos && s.find('e') == std::string::npos) {
        s += ".0";
    }
    std::cout << "float: " << s << "f" << std::endl;
}

static void formatAndPrintDouble(double d) {
    std::stringstream ss;
    ss << d;
    std::string s = ss.str();
    if (s.find('.') == std::string::npos && s.find('e') == std::string::npos) {
        s += ".0";
    }
    std::cout << "double: " << s << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: ";
        if (std::isprint(c)) {
            std::cout << "'" << c << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        formatAndPrintFloat(static_cast<float>(c));
        formatAndPrintDouble(static_cast<double>(c));
        return;
    }
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        char c = literal[1];
        std::cout << "char: ";
        if (std::isprint(c)) {
            std::cout << "'" << c << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        formatAndPrintFloat(static_cast<float>(c));
        formatAndPrintDouble(static_cast<double>(c));
        return;
    }

    if (isPseudoLiteral(literal)) {
        printPseudo(literal);
        return;
    }

    bool hasSuffixF = false;
    std::string parseStr = literal;
    if (parseStr.length() > 1 && (parseStr[parseStr.length() - 1] == 'f' || parseStr[parseStr.length() - 1] == 'F')) {
        char lastBefore = parseStr[parseStr.length() - 2];
        if (std::isdigit(lastBefore) || lastBefore == '.') {
            parseStr = parseStr.substr(0, parseStr.length() - 1);
            hasSuffixF = true;
        }
    }

    char* endptr;
    errno = 0;
    double d_val = std::strtod(parseStr.c_str(), &endptr);
    if (errno == ERANGE || endptr == parseStr.c_str() || *endptr != '\0') {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (hasSuffixF) {
        float f = static_cast<float>(d_val);

        // char conversion
        std::cout << "char: ";
        if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max() || f != f) {
            std::cout << "impossible" << std::endl;
        } else {
            char c = static_cast<char>(f);
            if (std::isprint(c)) {
                std::cout << "'" << c << "'" << std::endl;
            } else {
                std::cout << "Non displayable" << std::endl;
            }
        }

        // int conversion
        std::cout << "int: ";
        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max() || f != f) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << static_cast<int>(f) << std::endl;
        }

        // float conversion
        formatAndPrintFloat(f);

        // double conversion
        formatAndPrintDouble(static_cast<double>(f));

    } else {
        //compare
        bool isDouble = (literal.find('.') != std::string::npos ||
                         literal.find('e') != std::string::npos ||
                         literal.find('E') != std::string::npos);
        
        bool fitsInInt = (d_val >= std::numeric_limits<int>::min() && d_val <= std::numeric_limits<int>::max());

        if (!isDouble && fitsInInt) {
            int i = static_cast<int>(d_val);

            // char conversion
            std::cout << "char: ";
            if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
                std::cout << "impossible" << std::endl;
            } else {
                char c = static_cast<char>(i);
                if (std::isprint(c)) {
                    std::cout << "'" << c << "'" << std::endl;
                } else {
                    std::cout << "Non displayable" << std::endl;
                }
            }

            // int conversion
            std::cout << "int: " << i << std::endl;

            // float conversion
            formatAndPrintFloat(static_cast<float>(i));

            // double conversion
            formatAndPrintDouble(static_cast<double>(i));

        } else {
            // Actual type: double
            double d = d_val;

            // char conversion
            std::cout << "char: ";
            if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || d != d) {
                std::cout << "impossible" << std::endl;
            } else {
                char c = static_cast<char>(d);
                if (std::isprint(c)) {
                    std::cout << "'" << c << "'" << std::endl;
                } else {
                    std::cout << "Non displayable" << std::endl;
                }
            }

            // int conversion
            std::cout << "int: ";
            if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || d != d) {
                std::cout << "impossible" << std::endl;
            } else {
                std::cout << static_cast<int>(d) << std::endl;
            }

            // float conversion
            std::cout << "float: ";
            if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()) {
                std::cout << "impossible" << std::endl;
            } else {
                formatAndPrintFloat(static_cast<float>(d));
            }

            // double conversion
            formatAndPrintDouble(d);
        }
    }
}
