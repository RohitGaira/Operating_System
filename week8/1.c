#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct memory {
    int size;
    bool isallocated;
} memory;
int first_fit(memory *m, int s, int n) {
    for (int i = 0; i < n; i++) {
        if (m[i].size >= s && !m[i].isallocated) {
            m[i].size -= s;
            m[i].isallocated = true;
            return i + 1;
        }
    }
    return -1;
}
int findmin(memory *m, int pro, int n) {
    int min = INT_MAX;
    int d = -1;
    for (int i = 0; i < n; i++) {
        if (!m[i].isallocated && m[i].size >= pro && (m[i].size - pro) < min) {
            min = m[i].size - pro;
            d = i;
        }
    }
    return d;
}
void best_fit(memory *m, int pro, int n) {
    int d = findmin(m, pro, n);
    if (d != -1) {
        m[d].size -= pro;
        m[d].isallocated = true;
        printf("%d  Allocated in block %d (Best Fit)\n", pro, d + 1);
    } else {
        printf("%d  No suitable free block available (Best Fit)\n", pro);
    }
}
int findmax(memory *m, int pro, int n) {
    int max = INT_MIN;
    int d = -1;
    for (int i = 0; i < n; i++) {
        if (!m[i].isallocated && m[i].size >= pro && (m[i].size - pro) > max) {
            max = m[i].size - pro;
            d = i;
        }
    }
    return d;
}
void worst_fit(memory *m, int pro, int n) {
    int d = findmax(m, pro, n);
    if (d != -1) {
        m[d].size -= pro;
        m[d].isallocated = true;
        printf("%d  Allocated in block %d (Worst Fit)\n", pro, d + 1);
    } else {
        printf("%d  No suitable free block available (Worst Fit)\n", pro);
    }
}
int main() {
    int n, p, choice;
    printf("Enter the number of free blocks available: ");
    scanf("%d", &n);
    memory m[n];
    printf("Enter the sizes of memory blocks:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &(m[i].size));
        m[i].isallocated = false;
    }
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    int processes[p];
    printf("Enter the sizes of processes:\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &processes[i]);
    }
    printf("\nMenu:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\n--- FIRST FIT ALLOCATION ---\n");
            for (int i = 0; i < p; i++) {
                int t = first_fit(m, processes[i], n);
                if (t >= 0)
                    printf("%d  Allocated in block %d\n", processes[i], t);
                else
                    printf("%d  No free block available\n", processes[i]);
            }
            break;
        case 2:
            printf("\n--- BEST FIT ALLOCATION ---\n");
            for (int i = 0; i < p; i++) {
                best_fit(m, processes[i], n);
            }
            break;
        case 3:
            printf("\n--- WORST FIT ALLOCATION ---\n");
            for (int i = 0; i < p; i++) {
                worst_fit(m, processes[i], n);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
}
