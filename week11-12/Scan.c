#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of disk requests : ");
    scanf("%d", &n);

    int requests[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    int head = requests[0]; // first request is head
    int total_requests = n - 1;
    int seek_time = 0, direction, index = 0;
    // Shift remaining requests (remove the first one)
    for (int i = 0; i < total_requests; i++)
        requests[i] = requests[i + 1];
    
    // Automatically decide direction based on first request
    if (requests[0] > head)
        direction = 1; // move right
    else
        direction = 0; // move left
    // Sort remaining requests
    for (int i = 0; i < total_requests - 1; i++) {
        for (int j = i + 1; j < total_requests; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
    // Find first request greater than head
    for (int i = 0; i < total_requests; i++) {
        if (head < requests[i]) {
            index = i;
            break;
        }
    }

    // SCAN algorithm
    if (direction == 1) {
        // Move right first
        for (int i = index; i < total_requests; i++) {
            seek_time += abs(head - requests[i]);
            head = requests[i];
        }
        seek_time += abs(head - 199); // end of disk
        head = 199;
        for (int i = index - 1; i >= 0; i--) {
            seek_time += abs(head - requests[i]);
            head = requests[i];
        }
    } else {
        // Move left first
        for (int i = index - 1; i >= 0; i--) {
            seek_time += abs(head - requests[i]);
            head = requests[i];
        }
        seek_time += abs(head - 0);
        head = 0;
        for (int i = index; i < total_requests; i++) {
            seek_time += abs(head - requests[i]);
            head = requests[i];
        }
    }

    printf("Total seek movement : %d\n", seek_time);
    return 0;
}
