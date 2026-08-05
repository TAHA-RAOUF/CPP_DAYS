#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>
# include <cerrno>
# include <cmath>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valStr, float& val) const;
    std::string trim(const std::string& str) const;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dbPath);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& dbPath);
    void processInput(const std::string& inputPath) const;
};

#endif
