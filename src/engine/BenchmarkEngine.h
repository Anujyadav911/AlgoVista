#ifndef BENCHMARK_ENGINE_H
#define BENCHMARK_ENGINE_H

#include <vector>
#include "AlgorithmRegistry.h"

class BenchmarkEngine {
private:
    AlgorithmRegistry& registry;

public:
    BenchmarkEngine(AlgorithmRegistry& registry);

    void runSingle(const std::vector<int>& data);
    void runScale(const std::vector<std::vector<int>>& datasets);
};

#endif
