package algovista.input;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class InputGenerator {
    private final Scanner scanner = new Scanner(System.in);
    private final Random random = new Random(System.currentTimeMillis());

    public int readBenchmarkMode() {
        System.out.println("Benchmark Mode:");
        System.out.println("1. Single input");
        System.out.println("2. Scale test (RANDOM)");
        System.out.print("Enter choice: ");
        return scanner.nextInt();
    }

    public int[] generateSingle() {
        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();

        int[] data = new int[n];

        System.out.println("Choose input type:");
        System.out.println("1. Manual input");
        System.out.println("2. Random input");
        System.out.print("Enter choice: ");
        int choice = scanner.nextInt();

        if (choice == 1) {
            System.out.println("Enter " + n + " numbers:");
            for (int i = 0; i < n; i++) {
                data[i] = scanner.nextInt();
            }
        } else {
            for (int i = 0; i < n; i++) {
                data[i] = random.nextInt(10000);
            }
        }

        return data;
    }

    public List<int[]> generateScaleRandom() {
        int[] sizes = {100, 500, 1000, 5000};
        List<int[]> datasets = new ArrayList<>();

        for (int n : sizes) {
            int[] data = new int[n];
            for (int i = 0; i < n; i++) {
                data[i] = random.nextInt(100000);
            }
            datasets.add(data);
        }

        return datasets;
    }
}
