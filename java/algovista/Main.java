package algovista;

import algovista.engine.AlgorithmRegistry;
import algovista.engine.BenchmarkEngine;
import algovista.input.InputGenerator;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("AlgoVista Engine Started\n");

        InputGenerator inputGen = new InputGenerator();
        AlgorithmRegistry registry = new AlgorithmRegistry();
        registry.registerSortingAlgorithms();

        BenchmarkEngine engine = new BenchmarkEngine(registry);

        int mode = inputGen.readBenchmarkMode();

        if (mode == 1) {
            int[] data = inputGen.generateSingle();
            engine.runSingle(data);
        } else {
            List<int[]> datasets = inputGen.generateScaleRandom();
            engine.runScale(datasets);
        }
    }
}
