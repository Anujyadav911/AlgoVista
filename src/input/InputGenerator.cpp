#include "InputGenerator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::vector<int> InputGenerator::generateSingle() {
    int n, choice;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<int> data(n);

    std::cout << "Choose input type:\n";
    std::cout << "1. Manual input\n";
    std::cout << "2. Random input\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter " << n << " numbers:\n";
        for (int i = 0; i < n; i++)
            std::cin >> data[i];
    } else {
        std::srand(std::time(nullptr));
        for (int i = 0; i < n; i++)
            data[i] = std::rand() % 10000;
    }

    return data;
}

std::vector<std::vector<int>> InputGenerator::generateScaleRandom() {
    std::vector<int> sizes = {100, 500, 1000, 5000};
    std::vector<std::vector<int>> datasets;

    std::srand(std::time(nullptr));

    for (int n : sizes) {
        std::vector<int> data(n);
        for (int i = 0; i < n; i++)
            data[i] = std::rand() % 100000;

        datasets.push_back(data);
    }

    return datasets;
}
