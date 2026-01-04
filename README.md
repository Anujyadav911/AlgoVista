# AlgoVista 🚀

### A High-Performance C++ Sorting Algorithm Benchmarking Framework

AlgoVista is a **modular C++ benchmarking framework** designed to analyze, compare, and rank classical sorting algorithms across varying input sizes and distributions.

The project focuses on **performance engineering, clean architecture, and reproducible benchmarking**, making it suitable for **product-based company interviews** and **systems-focused roles**.

---

## ✨ Key Features

- 📊 Benchmarks multiple sorting algorithms with **microsecond-level precision**
- 🔁 Uses **adaptive averaging** to avoid 0 ms timing artifacts
- 🧩 **Extensible architecture** – add new algorithms with minimal changes
- 📈 **Scale testing** on increasing input sizes
- 📝 Automatically exports results to **CSV with metadata and ranking**
- ⚙️ Written in **modern C++ (STL + chrono)**, no external dependencies

---

## 🧠 Algorithms Implemented

### Comparison-Based Sorts
- **Bubble Sort**
- **Insertion Sort**
- **Selection Sort**
- **Quick Sort**
- **Heap Sort**
- **Merge Sort**

### Non-Comparison Sort
- **Counting Sort** (with safety guard on value range)

This coverage allows comparison between:
- O(n²) vs O(n log n)
- Average-case vs worst-case guarantees
- Comparison vs non-comparison sorting

---

## 🏗️ Project Architecture

```
AlgoVista/
├── src/
│   ├── main.cpp                    # Entry point
│   ├── algorithms/                 # Sorting algorithm implementations
│   │   ├── SortingAlgorithm.h      # Common interface
│   │   ├── BubbleSort.*
│   │   ├── InsertionSort.*
│   │   ├── SelectionSort.*
│   │   ├── QuickSort.*
│   │   ├── HeapSort.*
│   │   ├── MergeSort.*
│   │   └── CountingSort.*
│   ├── engine/                     # Benchmark orchestration
│   │   ├── AlgorithmRegistry.*
│   │   └── BenchmarkEngine.*
│   ├── input/                      # Input generation
│   │   └── InputGenerator.*
│   ├── benchmark/
│   │   └── Timer.h                 # High-resolution timer
│   └── utils/
│       └── Logger.h
├── benchmark_results.csv           # Auto-generated benchmark report
└── README.md
```

### Design Principles
- **Open–Closed Principle**: New algorithms can be added without modifying benchmark logic
- **Single Responsibility**: Each module has a clear purpose
- **Fair Benchmarking**: Same dataset used across all algorithms per run

---

## ▶️ How It Works

1. User selects benchmark mode:
   - Single input
   - Scale test (random input)
2. Input data is generated once
3. Each algorithm:
   - Runs multiple iterations
   - Execution time is averaged
4. Results are:
   - Printed to console
   - Exported to CSV with ranking

---

## 🧪 Benchmark Methodology

- **Timing Unit**: Microseconds (µs)
- **Iterations**:
  - Small input (<1000): 200 runs
  - Large input (≥1000): 20 runs
- **Minimum clamp**: Times < 1 µs are clamped to avoid misleading 0.00 values
- **Ranking**: Algorithms ranked per input size by average time

---

## 📄 Sample CSV Output

```csv
# AlgoVista Benchmark Report
# InputType: RANDOM
# TimeUnit: Microseconds (µs)
# Iterations: Adaptive (200 for small, 20 for large)

Algorithm,InputSize,AvgTimeMicroseconds,Rank
Quick Sort,100,1.00,1
Heap Sort,100,39.99,2
Merge Sort,100,200.02,5
Bubble Sort,100,245.65,6
```

The CSV is Excel / Google Sheets friendly and ready for plotting.

---

## 📈 Observations

- O(n²) algorithms (Bubble, Selection, Insertion) degrade rapidly with input size
- Quick Sort performs best on average for random input
- Heap Sort provides stable O(n log n) performance
- Counting Sort outperforms others when value range is small
- Benchmark results closely match theoretical expectations

---

## 🛠️ Build & Run (Windows – MinGW)

From `src/` directory:

```bash
g++ main.cpp engine/BenchmarkEngine.cpp engine/AlgorithmRegistry.cpp \
    algorithms/BubbleSort.cpp algorithms/InsertionSort.cpp algorithms/SelectionSort.cpp \
    algorithms/QuickSort.cpp algorithms/HeapSort.cpp algorithms/MergeSort.cpp \
    algorithms/CountingSort.cpp input/InputGenerator.cpp -o algovista
```

Run:

```bash
./algovista
```

---

## 🎯 Why This Project?

This project demonstrates:
- Strong understanding of data structures & algorithms
- Practical performance measurement
- Clean, extensible C++ system design
- Ability to translate theory into measurable results

---

## 📌 Future Enhancements (Optional)

- Sorted / reverse-sorted input benchmarks
- Command-line arguments
- Additional non-comparison sorts (Radix, Bucket)
- Automated graph generation

---

## 👤 Author

**Anuj Yadav**  
Final-year B.Tech student (CSE)  
Focused on C++, DSA, and performance-oriented systems

---

## 📝 License

This project is open source and available for educational purposes.

