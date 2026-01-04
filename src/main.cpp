#include <iostream>

#include "engine/BenchmarkEngine.h"
#include "engine/AlgorithmRegistry.h"
#include "input/InputGenerator.h"

int main() {
    std::cout << "AlgoVista Engine Started\n\n";

    InputGenerator inputGen;
    AlgorithmRegistry registry;
    registry.registerSortingAlgorithms();

    BenchmarkEngine engine(registry);

    int mode;
    std::cout << "Benchmark Mode:\n";
    std::cout << "1. Single input\n";
    std::cout << "2. Scale test (RANDOM)\n";
    std::cout << "Enter choice: ";
    std::cin >> mode;

    if (mode == 1) {
        auto data = inputGen.generateSingle();
        engine.runSingle(data);
    } else {
        auto datasets = inputGen.generateScaleRandom();
        engine.runScale(datasets);
    }

    return 0;
}
