#ifndef INPUT_GENERATOR_H
#define INPUT_GENERATOR_H

#include <vector>

class InputGenerator {
public:
    std::vector<int> generateSingle();
    std::vector<std::vector<int>> generateScaleRandom();
};

#endif
