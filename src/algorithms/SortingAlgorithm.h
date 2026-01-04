#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

#include <vector>
#include <string>

class SortingAlgorithm {
public:
    virtual std::string name() const = 0;
    virtual void sort(std::vector<int>& arr) = 0;
    virtual ~SortingAlgorithm() = default;
};

#endif
