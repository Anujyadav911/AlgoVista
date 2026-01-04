#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm {
public:
    std::string name() const override;
    void sort(std::vector<int>& arr) override;

private:
    void mergeSort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int mid, int right);
};

#endif
