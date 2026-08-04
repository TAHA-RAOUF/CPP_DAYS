#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <sys/time.h>
# include <algorithm>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    // Helper functions for vector
    static void sortVector(std::vector<int>& arr);
    // Helper functions for deque
    static void sortDeque(std::deque<int>& arr);

    static std::vector<size_t> generateJacobsthalSequence(size_t n);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool parseInput(int argc, char** argv);
    void run();
};

#endif
