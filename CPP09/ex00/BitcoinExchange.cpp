#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
    loadDatabase(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    } else if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (isLeap && day > 29) return false;
        if (!isLeap && day > 28) return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valStr, float& val) const {
    if (valStr.empty())
        return false;

    
    std::string lowerStr = valStr;
    for (size_t i = 0; i < lowerStr.length(); ++i)
        lowerStr[i] = static_cast<char>(std::tolower(lowerStr[i]));
    // Reject nan, inf, +inf, -inf 
    if (lowerStr.find("nan") != std::string::npos || lowerStr.find("inf") != std::string::npos)
        return false;

    errno = 0;
    char* endptr;
    val = std::strtof(valStr.c_str(), &endptr);

    if (endptr == valStr.c_str() || *endptr != '\0')
        return false;

    if (errno == ERANGE || std::isnan(val) || std::isinf(val))
        return false;

    return true;
}

bool BitcoinExchange::loadDatabase(const std::string& dbPath) {
    std::ifstream file(dbPath.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // header line
    while (std::getline(file, line)) {
        if (trim(line).empty())
            continue;
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        std::string date = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));

        if (!isValidDate(date))
            continue;

        float rate;
        if (!isValidValue(rateStr, rate) || rate < 0)
            continue;

        _database[date] = rate;
    }
    file.close();
    return true;
}

void BitcoinExchange::processInput(const std::string& inputPath) const {
    std::ifstream file(inputPath.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // header line: date | value
    while (std::getline(file, line)) {
        if (trim(line).empty())
            continue;
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valStr = trim(line.substr(pipePos + 1));

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float val;
        if (!isValidValue(valStr, val)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (val < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (val > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
        if (it == _database.end() || it->first != date) {
            if (it == _database.begin()) {
                std::cout << "Error: date precedes database history." << std::endl;
                continue;
            }
            --it;
        }

        float result = val * it->second;
        std::cout << date << " => " << val << " = " << result << std::endl;
    }
    file.close();
}
