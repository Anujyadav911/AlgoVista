#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "SortingAlgorithm.h"

class CountingSort : public SortingAlgorithm {
public:
    std::string name() const override;
    void sort(std::vector<int>& arr) override;
};

#endif
