#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 8000 // number of nodes
#define M 160000 // number of edges

int graph[N][N]; 
int active[N]; 
int new_active[N]; 

void serial_icm() {
    int i, j, k, p;
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            if (active[i] == 1) {
                for (j = 0; j < N; j++) {
                    if (graph[i][j] == 1 && active[j] == 0) {
                        p = rand() % 100;
                        if (p < 50) {
                            new_active[j] = 1;
                        }
                    }
                }
            }
        }
        for (i = 0; i < N; i++) {
            if (new_active[i] == 1) {
                active[i] = 1;
                new_active[i] = 0;
            }
        }
    }
}

void parallel_icm() {
    int i, j, k, p;
    #pragma omp parallel private(i,j,k,p) shared(graph,active,new_active)
    {
        for (k = 0; k < N; k++) {
            #pragma omp for
            for (i = 0; i < N; i++) {
                if (active[i] == 1) {
                    for (j = 0; j < N; j++) {
                        if (graph[i][j] == 1 && active[j] == 0) {
                            p = rand() % 100;
                            if (p < 50) {
                                new_active[j] = 1;
                            }
                        }
                    }
                }
            }
            #pragma omp barrier
            #pragma omp for
            for (i = 0; i < N; i++) {
                if (new_active[i] == 1) {
                    active[i] = 1;
                    new_active[i] = 0;
                }
            }
            #pragma omp barrier
        }
    }
}

double calculate_coverage() {
    int i, coverage = 0;
    for (i = 0; i < N; i++) {
        if (active[i] == 1) {
            coverage++;
        }
    }
    return (double)coverage / N;
}

int main() {
    int i, j, k, p;
    double start_serial, end_serial, start_parallel, end_parallel;

for (k = 0; k < M; k++) {
    i = rand() % N;
    j = rand() % N;
    if (rand() % 100 < 10) { 
        graph[i][j] = 1;
    }
}
    // Setting the initial active nodes
    active[0] = 1;

    start_serial = omp_get_wtime();
    serial_icm();
    end_serial = omp_get_wtime();

    double serial_coverage = calculate_coverage();

    // Resetting the active and new_active arrays
    for (i = 0; i < N; i++) {
        active[i] = 0;
        new_active[i] = 0;
    }
    active[0] = 1;
    start_parallel = omp_get_wtime();
    parallel_icm();
    end_parallel = omp_get_wtime();

    double parallel_coverage = calculate_coverage();

    printf("Serial time taken: %f seconds\n", end_serial - start_serial);
    printf("Serial coverage: %f\n", serial_coverage);
    printf("Parallel time taken: %f seconds\n", end_parallel - start_parallel);
    printf("Parallel coverage: %f\n", parallel_coverage);

    return 0;
}
