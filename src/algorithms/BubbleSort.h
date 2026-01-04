#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm {
public:
    std::string name() const override;
    void sort(std::vector<int>& arr) override;
};

#endif
