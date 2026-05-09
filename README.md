# AlgoVista 🚀

### A High-Performance Java Sorting Algorithm Benchmarking Framework

AlgoVista is a **modular Java benchmarking framework** designed to analyze, compare, and rank classical sorting algorithms across varying input sizes and distributions.

The project focuses on **performance engineering, clean architecture, and reproducible benchmarking**, making it suitable for **product-based company interviews** and **systems-focused roles**.

---

## ✨ Key Features

- 📊 Benchmarks multiple sorting algorithms with **microsecond-level precision**
- 🔁 Uses **adaptive averaging** to avoid 0 ms timing artifacts
- 🧩 **Extensible architecture** – add new algorithms with minimal changes
- 📈 **Scale testing** on increasing input sizes
- 📝 Automatically exports results to **CSV with metadata and ranking**
- ⚙️ Written in **modern Java (standard library only)**, no external dependencies

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
├── java/
│   └── algovista/
│       ├── Main.java               # Entry point (mode selection)
│       ├── benchmark/
│       │   └── Timer.java          # High-resolution timer (µs)
│       ├── utils/
│       │   └── Logger.java         # Simple console logger
│       ├── algorithms/             # Sorting algorithm implementations
│       │   ├── SortingAlgorithm.java
│       │   ├── BubbleSort.java
│       │   ├── InsertionSort.java
│       │   ├── SelectionSort.java
│       │   ├── QuickSort.java
│       │   ├── HeapSort.java
│       │   ├── MergeSort.java
│       │   └── CountingSort.java
│       ├── engine/                 # Benchmark orchestration
│       │   ├── AlgorithmRegistry.java
│       │   └── BenchmarkEngine.java
│       └── input/                  # Input generation (manual + random)
│           └── InputGenerator.java
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
- **Per-algorithm stats**: For each algorithm and input size, **average**, **best**, and **worst** times are tracked
- **Ranking**: Algorithms ranked per input size by average time and written to CSV

---

## 📄 Sample CSV Output

```csv
# AlgoVista Benchmark Report
# InputType: RANDOM
# TimeUnit: Microseconds (µs)
# Iterations: Adaptive (200 for small, 20 for large)

Algorithm,InputSize,AvgTimeMicroseconds,BestTimeMicroseconds,WorstTimeMicroseconds,Rank
Heap Sort,100,1.00,1.00,1.00,1
Quick Sort,100,46.31,1.00,8000.00,2
Insertion Sort,100,71.28,1.00,14058.00,3
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

## 🛠️ Build & Run (Java)

From the repository root:

```bash
mkdir -p out
javac -d out $(find java -name "*.java")
java -cp out algovista.Main
```

---

## 🎯 Why This Project?

This project demonstrates:
- Strong understanding of data structures & algorithms
- Practical performance measurement
- Clean, extensible Java system design
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
Focused on Java, DSA, and performance-oriented systems

---

## 📝 License

This project is open source and available for educational purposes.

