#include "AlgorithmRegistry.h"
#include "../algorithms/BubbleSort.h"
#include "../algorithms/InsertionSort.h"
#include "../algorithms/SelectionSort.h"
#include "../algorithms/QuickSort.h"
#include "../algorithms/HeapSort.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/CountingSort.h"


void AlgorithmRegistry::registerSortingAlgorithms() {
    sortingAlgorithms.push_back(std::make_unique<BubbleSort>());
    sortingAlgorithms.push_back(std::make_unique<InsertionSort>());
    sortingAlgorithms.push_back(std::make_unique<SelectionSort>());
    sortingAlgorithms.push_back(std::make_unique<QuickSort>());
    sortingAlgorithms.push_back(std::make_unique<HeapSort>());
    sortingAlgorithms.push_back(std::make_unique<MergeSort>());
    sortingAlgorithms.push_back(std::make_unique<CountingSort>());
}

const std::vector<std::unique_ptr<SortingAlgorithm>>&
AlgorithmRegistry::getSortingAlgorithms() const {
    return sortingAlgorithms;
}
