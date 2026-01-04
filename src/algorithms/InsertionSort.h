#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "SortingAlgorithm.h"

class InsertionSort : public SortingAlgorithm {
public:
    std::string name() const override;
    void sort(std::vector<int>& arr) override;
};

#endif
