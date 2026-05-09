package algovista.engine;

import algovista.algorithms.BubbleSort;
import algovista.algorithms.CountingSort;
import algovista.algorithms.HeapSort;
import algovista.algorithms.InsertionSort;
import algovista.algorithms.MergeSort;
import algovista.algorithms.QuickSort;
import algovista.algorithms.SelectionSort;
import algovista.algorithms.SortingAlgorithm;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class AlgorithmRegistry {
    private final List<SortingAlgorithm> sortingAlgorithms = new ArrayList<>();

    public void registerSortingAlgorithms() {
        sortingAlgorithms.add(new BubbleSort());
        sortingAlgorithms.add(new InsertionSort());
        sortingAlgorithms.add(new SelectionSort());
        sortingAlgorithms.add(new QuickSort());
        sortingAlgorithms.add(new HeapSort());
        sortingAlgorithms.add(new MergeSort());
        sortingAlgorithms.add(new CountingSort());
    }

    public List<SortingAlgorithm> getSortingAlgorithms() {
        return Collections.unmodifiableList(sortingAlgorithms);
    }
}
