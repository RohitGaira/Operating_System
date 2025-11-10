#include<stdio.h>
int main(){
    int n, head, seek_time=0, curr;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &requests[i]);
    }
    head=requests[0];  // Initialize head to the first request as in question head input is not given separately
    for(int i=0; i<n; i++){
        curr = requests[i];
        seek_time += (curr > head) ? (curr - head) : (head - curr);
        head = curr;
    }
    printf("Total Seek Time: %d\n", seek_time);
    return 0;
}
