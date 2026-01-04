#ifndef ALGORITHM_REGISTRY_H
#define ALGORITHM_REGISTRY_H

#include <vector>
#include <memory>
#include "../algorithms/SortingAlgorithm.h"

class AlgorithmRegistry {
private:
    std::vector<std::unique_ptr<SortingAlgorithm>> sortingAlgorithms;

public:
    void registerSortingAlgorithms();
    const std::vector<std::unique_ptr<SortingAlgorithm>>& getSortingAlgorithms() const;
};

#endif
