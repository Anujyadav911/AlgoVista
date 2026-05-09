package algovista.algorithms;

public class CountingSort implements SortingAlgorithm {
    @Override
    public String name() {
        return "Counting Sort";
    }

    @Override
    public void sort(int[] arr) {
        if (arr.length == 0) {
            return;
        }

        int maxElement = arr[0];
        for (int value : arr) {
            if (value > maxElement) {
                maxElement = value;
            }
        }

        if (maxElement > 1_000_000) {
            return;
        }

        int[] count = new int[maxElement + 1];

        for (int value : arr) {
            count[value]++;
        }

        int index = 0;
        for (int i = 0; i <= maxElement; i++) {
            while (count[i]-- > 0) {
                arr[index++] = i;
            }
        }
    }
}
