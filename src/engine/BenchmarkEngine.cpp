#include <fstream>
#include <iomanip>
#include <algorithm>


#include "BenchmarkEngine.h"
#include "../../benchmark/Timer.h"
#include <iostream>
#include <limits>

BenchmarkEngine::BenchmarkEngine(AlgorithmRegistry& registry)
    : registry(registry) {}

void BenchmarkEngine::runSingle(const std::vector<int>& data) {
    int ITERATIONS = (data.size() < 1000) ? 200 : 20;

    std::cout << "\n--- Benchmark Results (Average over "
              << ITERATIONS << " runs) ---\n";

    double bestAvgTime = std::numeric_limits<double>::max();
    std::string fastestAlgo;
    std::vector<int> bestSortedOutput;

    for (const auto& algo : registry.getSortingAlgorithms()) {
        double totalTime = 0.0;
        std::vector<int> temp;

        for (int i = 0; i < ITERATIONS; i++) {
            temp = data;
            Timer timer;
            timer.start();
            algo->sort(temp);
            totalTime += timer.stop();
        }

        double avgTime = totalTime / ITERATIONS;

        std::cout << algo->name()
                  << " average time: "
                  << avgTime << " µs\n";

        if (avgTime < bestAvgTime) {
            bestAvgTime = avgTime;
            fastestAlgo = algo->name();
            bestSortedOutput = temp;
        }
    }

    std::cout << "\nFastest Algorithm: " << fastestAlgo << "\n";
    std::cout << "Sorted Output (" << fastestAlgo << "): ";
    for (int x : bestSortedOutput) std::cout << x << " ";
    std::cout << "\n";
}

void BenchmarkEngine::runScale(const std::vector<std::vector<int>>& datasets) {
    std::ofstream csv("benchmark_results.csv");

    // ---- Metadata Header ----
    csv << "# AlgoVista Benchmark Report\n";
    csv << "# InputType: RANDOM\n";
    csv << "# TimeUnit: Microseconds (µs)\n";
    csv << "# Iterations: Adaptive (200 for small, 20 for large)\n";
    csv << "# ------------------------------------------\n";
    csv << "Algorithm,InputSize,AvgTimeMicroseconds,Rank\n";

    csv << std::fixed << std::setprecision(2);

    std::cout << "\n=== SCALE BENCHMARK (RANDOM INPUT) ===\n";

    for (const auto& data : datasets) {
        int n = data.size();
        int ITERATIONS = (n < 1000) ? 200 : 20;

        std::cout << "\nInput Size: " << n << "\n";

        // Store results for ranking
        struct Result {
            std::string name;
            double time;
        };

        std::vector<Result> results;

        for (const auto& algo : registry.getSortingAlgorithms()) {
            double totalTime = 0.0;
            std::vector<int> temp;

            for (int i = 0; i < ITERATIONS; i++) {
                temp = data;
                Timer timer;
                timer.start();
                algo->sort(temp);
                totalTime += timer.stop();
            }

            double avgTime = totalTime / ITERATIONS;

            // ---- FIX 0.00 ISSUE ----
            if (avgTime < 1.0)
                avgTime = 1.0;

            results.push_back({algo->name(), avgTime});

            std::cout << algo->name()
                      << " avg: "
                      << avgTime << " µs\n";
        }

        // ---- Rank by performance ----
        std::sort(results.begin(), results.end(),
                  [](const Result& a, const Result& b) {
                      return a.time < b.time;
                  });

        // ---- Write ranked results to CSV ----
        for (size_t i = 0; i < results.size(); i++) {
            csv << results[i].name << ","
                << n << ","
                << results[i].time << ","
                << (i + 1) << "\n";
        }
    }

    csv.close();
    std::cout << "\nCSV report generated: benchmark_results.csv\n";
}
