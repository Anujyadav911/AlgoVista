package algovista.benchmark;

public class Timer {
    private long startTime;

    public void start() {
        startTime = System.nanoTime();
    }

    // Returns elapsed time in microseconds
    public double stop() {
        long endTime = System.nanoTime();
        return (endTime - startTime) / 1000.0;
    }

    public void reset() {
        startTime = System.nanoTime();
    }
}
