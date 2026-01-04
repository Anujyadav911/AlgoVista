#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "SortingAlgorithm.h"

class HeapSort : public SortingAlgorithm {
public:
    std::string name() const override;
    void sort(std::vector<int>& arr) override;

private:
    void heapify(std::vector<int>& arr, int n, int i);
};

#endif
