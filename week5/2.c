#include <stdio.h>
#include <stdbool.h>
int main() {
    int p, r;
    printf("Enter number of processes : ");
    scanf("%d", &p);
    printf("Enter number of resources : ");
    scanf("%d", &r);
    int max[p][r], alloc[p][r], need[p][r];
    int total[r], available[r], finished[p];
    printf("Enter maximum requirement : \n");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            scanf("%d", &max[i][j]);
    printf("Enter allocated matrix : \n");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            scanf("%d", &alloc[i][j]);
    printf("Resource Vector : ");
    for(int i=0;i<r;i++)
        scanf("%d", &total[i]);
    for(int i=0;i<r;i++) {
        int sum = 0;
        for(int j=0;j<p;j++)
            sum += alloc[j][i];
        available[i] = total[i] - sum;
    }
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];
    for(int i=0;i<p;i++)
        finished[i] = 0;
    int count = 0;
    while(count < p) {
        bool found = false;
        for(int i=0;i<p;i++) {
            if(!finished[i]) {
                bool possible = true;
                for(int j=0;j<r;j++) {
                    if(need[i][j] > available[j]) {
                        possible = false;
                        break;
                    }}
                if(possible) {
                    for(int j=0;j<r;j++)
                        available[j] += alloc[i][j];
                    finished[i] = 1;
                    count++;
                    found = true;
                }}}
        if(!found) {
            printf("Deadlock detected");
            return 0;
        }}
    printf("No deadlock detected");
    return 0;
}
