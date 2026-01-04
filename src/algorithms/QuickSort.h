#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm {
public:
    std::string name() const override;
    void sort(std::vector<int>& arr) override;

private:
    void quickSort(std::vector<int>& arr, int low, int high);
    int partition(std::vector<int>& arr, int low, int high);
};

#endif
