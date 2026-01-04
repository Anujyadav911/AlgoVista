#include "CountingSort.h"
#include <vector>
#include <algorithm>

std::string CountingSort::name() const {
    return "Counting Sort";
}

void CountingSort::sort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int maxElement = *std::max_element(arr.begin(), arr.end());

    // Safety check: avoid unreasonable memory usage
    if (maxElement > 1'000'000) {
        // Fallback: do nothing (or could throw/log)
        return;
    }

    std::vector<int> count(maxElement + 1, 0);

    // Count occurrences
    for (int x : arr) {
        count[x]++;
    }

    // Reconstruct sorted array
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i]--) {
            arr[index++] = i;
        }
    }
}
