#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <limits>

#include "BenchmarkEngine.h"
#include "../../benchmark/Timer.h"

BenchmarkEngine::BenchmarkEngine(AlgorithmRegistry& registry)
    : registry(registry) {}

// --------------------------------------------------
// SINGLE INPUT BENCHMARK
// --------------------------------------------------
void BenchmarkEngine::runSingle(const std::vector<int>& data) {
    int ITERATIONS = (data.size() < 1000) ? 200 : 20;

    std::cout << "\n--- Benchmark Results (Average over "
              << ITERATIONS << " runs) ---\n";

    double bestAvgTime = std::numeric_limits<double>::max();
    std::string fastestAlgo;
    std::vector<int> bestSortedOutput;

    for (const auto& algo : registry.getSortingAlgorithms()) {
        double totalTime = 0.0;
        double bestTime = std::numeric_limits<double>::max();
        double worstTime = 0.0;

        std::vector<int> temp;

        for (int i = 0; i < ITERATIONS; i++) {
            temp = data;
            Timer timer;
            timer.start();
            algo->sort(temp);
            double t = timer.stop();

            if (t < 1.0) t = 1.0; // clamp

            totalTime += t;
            bestTime = std::min(bestTime, t);
            worstTime = std::max(worstTime, t);
        }

        double avgTime = totalTime / ITERATIONS;

        std::cout << algo->name()
                  << " | Avg: " << avgTime
                  << " µs | Best: " << bestTime
                  << " µs | Worst: " << worstTime
                  << " µs\n";

        if (avgTime < bestAvgTime) {
            bestAvgTime = avgTime;
            fastestAlgo = algo->name();
            bestSortedOutput = temp;
        }
    }

    std::cout << "\nFastest Algorithm (by Avg Time): " << fastestAlgo << "\n";
    std::cout << "Sorted Output (" << fastestAlgo << "): ";
    for (int x : bestSortedOutput) std::cout << x << " ";
    std::cout << "\n";
}

// --------------------------------------------------
// SCALE BENCHMARK (CSV + RANKING)
// --------------------------------------------------
void BenchmarkEngine::runScale(const std::vector<std::vector<int>>& datasets) {
    std::ofstream csv("benchmark_results.csv");

    // ---- Metadata ----
    csv << "# AlgoVista Benchmark Report\n";
    csv << "# InputType: RANDOM\n";
    csv << "# TimeUnit: Microseconds (µs)\n";
    csv << "# Iterations: Adaptive (200 for small, 20 for large)\n";
    csv << "# ------------------------------------------\n";
    csv << "Algorithm,InputSize,AvgTimeMicroseconds,"
           "BestTimeMicroseconds,WorstTimeMicroseconds,Rank\n";

    csv << std::fixed << std::setprecision(2);

    std::cout << "\n=== SCALE BENCHMARK (RANDOM INPUT) ===\n";

    for (const auto& data : datasets) {
        int n = data.size();
        int ITERATIONS = (n < 1000) ? 200 : 20;

        std::cout << "\nInput Size: " << n << "\n";

        struct Result {
            std::string name;
            double avg;
            double best;
            double worst;
        };

        std::vector<Result> results;

        for (const auto& algo : registry.getSortingAlgorithms()) {
            double totalTime = 0.0;
            double bestTime = std::numeric_limits<double>::max();
            double worstTime = 0.0;

            std::vector<int> temp;

            for (int i = 0; i < ITERATIONS; i++) {
                temp = data;
                Timer timer;
                timer.start();
                algo->sort(temp);
                double t = timer.stop();

                if (t < 1.0) t = 1.0;

                totalTime += t;
                bestTime = std::min(bestTime, t);
                worstTime = std::max(worstTime, t);
            }

            double avgTime = totalTime / ITERATIONS;

            results.push_back({algo->name(), avgTime, bestTime, worstTime});

            std::cout << algo->name()
                      << " avg: " << avgTime << " µs\n";
        }

        // ---- Rank by Avg Time ----
        std::sort(results.begin(), results.end(),
                  [](const Result& a, const Result& b) {
                      return a.avg < b.avg;
                  });

        // ---- Write CSV ----
        for (size_t i = 0; i < results.size(); i++) {
            csv << results[i].name << ","
                << n << ","
                << results[i].avg << ","
                << results[i].best << ","
                << results[i].worst << ","
                << (i + 1) << "\n";
        }
    }

    csv.close();
    std::cout << "\nCSV report generated: benchmark_results.csv\n";
}
