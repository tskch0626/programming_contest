#include<stdio.h>
#define MAX 100000

int main() {
    int N;
    int A[MAX];
    int x[MAX];

    scanf("%d", &N);

    int sum = 0;
    for (int i=0; i<N; i++) {
        scanf("%d", &A[i]);

        if (i%2==0) sum+=A[i];
        else sum-=A[i];
    }
    x[0] = sum;

    for (int i=0; i<N-2; i++) {
        x[i+1] = 2*A[i] - x[i];
    }
    x[N-1] = 2*A[N-1] - x[0];

    for (int i=0; i<N; i++) {
        printf("%d ", x[i]);
    }
    
    return 0;
}