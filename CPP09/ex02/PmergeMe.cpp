#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) return false;
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j]))
                return false;
        }
        long val = std::atol(arg.c_str());
        if (val <= 0 || val > 2147483647)
            return false;
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
    return !_vec.empty();
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> jacob;
    if (n == 0) return jacob;
    jacob.push_back(1);
    if (n == 1) return jacob;
    jacob.push_back(3);

    while (true) {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        if (next >= n) {
            jacob.push_back(next);
            break;
        }
        jacob.push_back(next);
    }
    return jacob;
}

// Vector implementation of Ford-Johnson
void PmergeMe::sortVector(std::vector<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    bool hasStray = (n % 2 != 0);
    int stray = 0;
    if (hasStray) {
        stray = arr.back();
        arr.pop_back();
    }

    // 1. Group into pairs & sort pairs
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // Extract larger elements and sort recursively
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    sortVector(mainChain);

    // Reconstruct pairs in sorted mainChain order
    std::vector<int> pend;
    std::vector<bool> pairUsed(pairs.size(), false);

    std::vector<int> sortedMainChain;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        int larger = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!pairUsed[j] && pairs[j].first == larger) {
                pairUsed[j] = true;
                pend.push_back(pairs[j].second);
                sortedMainChain.push_back(larger);
                break;
            }
        }
    }

    // Insert pend into mainChain using Jacobsthal order
    std::vector<int> result = sortedMainChain;
    // Insert b1 first
    if (!pend.empty()) {
        result.insert(result.begin(), pend[0]);
    }

    std::vector<size_t> jacobSeq = generateJacobsthalSequence(pend.size());
    size_t lastInsertedIndex = 1;

    for (size_t i = 1; i < jacobSeq.size(); ++i) {
        size_t targetIndex = jacobSeq[i];
        if (targetIndex > pend.size())
            targetIndex = pend.size();

        for (size_t j = targetIndex; j > lastInsertedIndex; --j) {
            int elementToInsert = pend[j - 1];
            // Binary search insertion
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), elementToInsert);
            result.insert(pos, elementToInsert);
        }
        lastInsertedIndex = targetIndex;
    }

    if (hasStray) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), stray);
        result.insert(pos, stray);
    }

    arr = result;
}

// Deque implementation of Ford-Johnson
void PmergeMe::sortDeque(std::deque<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    bool hasStray = (n % 2 != 0);
    int stray = 0;
    if (hasStray) {
        stray = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    sortDeque(mainChain);

    std::deque<int> pend;
    std::vector<bool> pairUsed(pairs.size(), false);

    std::deque<int> sortedMainChain;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        int larger = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!pairUsed[j] && pairs[j].first == larger) {
                pairUsed[j] = true;
                pend.push_back(pairs[j].second);
                sortedMainChain.push_back(larger);
                break;
            }
        }
    }

    std::deque<int> result = sortedMainChain;
    if (!pend.empty()) {
        result.push_front(pend[0]);
    }

    std::vector<size_t> jacobSeq = generateJacobsthalSequence(pend.size());
    size_t lastInsertedIndex = 1;

    for (size_t i = 1; i < jacobSeq.size(); ++i) {
        size_t targetIndex = jacobSeq[i];
        if (targetIndex > pend.size())
            targetIndex = pend.size();

        for (size_t j = targetIndex; j > lastInsertedIndex; --j) {
            int elementToInsert = pend[j - 1];
            std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), elementToInsert);
            result.insert(pos, elementToInsert);
        }
        lastInsertedIndex = targetIndex;
    }

    if (hasStray) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), stray);
        result.insert(pos, stray);
    }

    arr = result;
}

static double getTimeUs() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0) + tv.tv_usec;
}

void PmergeMe::run() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << (i + 1 == _vec.size() ? "" : " ");
    }
    std::cout << std::endl;

    std::vector<int> vecCopy = _vec;
    std::deque<int> deqCopy = _deq;

    double startVec = getTimeUs();
    sortVector(vecCopy);
    double endVec = getTimeUs();
    double timeVec = endVec - startVec;

    double startDeq = getTimeUs();
    sortDeque(deqCopy);
    double endDeq = getTimeUs();
    double timeDeq = endDeq - startDeq;

    std::cout << "After:  ";
    for (size_t i = 0; i < vecCopy.size(); ++i) {
        std::cout << vecCopy[i] << (i + 1 == vecCopy.size() ? "" : " ");
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
