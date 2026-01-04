#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm {
public:
    std::string name() const override;
    void sort(std::vector<int>& arr) override;
};

#endif
