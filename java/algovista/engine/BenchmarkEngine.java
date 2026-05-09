package algovista.engine;

import algovista.algorithms.SortingAlgorithm;
import algovista.benchmark.Timer;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;

public class BenchmarkEngine {
    private final AlgorithmRegistry registry;

    public BenchmarkEngine(AlgorithmRegistry registry) {
        this.registry = registry;
    }

    public void runSingle(int[] data) {
        int iterations = (data.length < 1000) ? 200 : 20;

        System.out.println("\n--- Benchmark Results (Average over " + iterations + " runs) ---");

        double bestAvgTime = Double.MAX_VALUE;
        String fastestAlgo = "";
        int[] bestSortedOutput = new int[0];

        for (SortingAlgorithm algo : registry.getSortingAlgorithms()) {
            double totalTime = 0.0;
            double bestTime = Double.MAX_VALUE;
            double worstTime = 0.0;

            int[] temp = new int[0];

            for (int i = 0; i < iterations; i++) {
                temp = Arrays.copyOf(data, data.length);
                Timer timer = new Timer();
                timer.start();
                algo.sort(temp);
                double t = timer.stop();

                if (t < 1.0) {
                    t = 1.0;
                }

                totalTime += t;
                bestTime = Math.min(bestTime, t);
                worstTime = Math.max(worstTime, t);
            }

            double avgTime = totalTime / iterations;

            System.out.println(algo.name()
                    + " | Avg: " + String.format(Locale.US, "%.2f", avgTime)
                    + " µs | Best: " + String.format(Locale.US, "%.2f", bestTime)
                    + " µs | Worst: " + String.format(Locale.US, "%.2f", worstTime)
                    + " µs");

            if (avgTime < bestAvgTime) {
                bestAvgTime = avgTime;
                fastestAlgo = algo.name();
                bestSortedOutput = temp;
            }
        }

        System.out.println("\nFastest Algorithm (by Avg Time): " + fastestAlgo);
        System.out.print("Sorted Output (" + fastestAlgo + "): ");
        for (int value : bestSortedOutput) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    public void runScale(List<int[]> datasets) {
        try (PrintWriter csv = new PrintWriter(new BufferedWriter(new FileWriter("benchmark_results.csv")))) {
            csv.println("# AlgoVista Benchmark Report");
            csv.println("# InputType: RANDOM");
            csv.println("# TimeUnit: Microseconds (µs)");
            csv.println("# Iterations: Adaptive (200 for small, 20 for large)");
            csv.println("# ------------------------------------------");
            csv.println("Algorithm,InputSize,AvgTimeMicroseconds,BestTimeMicroseconds,WorstTimeMicroseconds,Rank");

            System.out.println("\n=== SCALE BENCHMARK (RANDOM INPUT) ===");

            for (int[] data : datasets) {
                int n = data.length;
                int iterations = (n < 1000) ? 200 : 20;

                System.out.println("\nInput Size: " + n);

                List<Result> results = new ArrayList<>();

                for (SortingAlgorithm algo : registry.getSortingAlgorithms()) {
                    double totalTime = 0.0;
                    double bestTime = Double.MAX_VALUE;
                    double worstTime = 0.0;

                    for (int i = 0; i < iterations; i++) {
                        int[] temp = Arrays.copyOf(data, data.length);
                        Timer timer = new Timer();
                        timer.start();
                        algo.sort(temp);
                        double t = timer.stop();

                        if (t < 1.0) {
                            t = 1.0;
                        }

                        totalTime += t;
                        bestTime = Math.min(bestTime, t);
                        worstTime = Math.max(worstTime, t);
                    }

                    double avgTime = totalTime / iterations;
                    results.add(new Result(algo.name(), avgTime, bestTime, worstTime));

                    System.out.println(algo.name() + " avg: " + String.format(Locale.US, "%.2f", avgTime) + " µs");
                }

                results.sort(Comparator.comparingDouble(Result::avg));

                for (int i = 0; i < results.size(); i++) {
                    Result r = results.get(i);
                    csv.println(r.name + ","
                            + n + ","
                            + String.format(Locale.US, "%.2f", r.avg) + ","
                            + String.format(Locale.US, "%.2f", r.best) + ","
                            + String.format(Locale.US, "%.2f", r.worst) + ","
                            + (i + 1));
                }
            }

            System.out.println("\nCSV report generated: benchmark_results.csv");
        } catch (IOException e) {
            System.err.println("Failed to write CSV report: " + e.getMessage());
        }
    }

    private static class Result {
        private final String name;
        private final double avg;
        private final double best;
        private final double worst;

        private Result(String name, double avg, double best, double worst) {
            this.name = name;
            this.avg = avg;
            this.best = best;
            this.worst = worst;
        }

        private double avg() {
            return avg;
        }
    }
}
