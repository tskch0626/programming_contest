#include<bits/stdc++.h>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    if (N==1) printf("No\n");
    else if (N%2==0) {
        int tmp = N;
        int i;
        for (i=N-1; i>0; i--) {
            tmp ^= i;
            if (tmp==0) break;
        }
        if (tmp==0) {
            printf("Yes\n");
            for (int j=1; j<2*N-1; j++) {
                if (j%N==0) continue;
                printf("%d %d\n", j, j+1);
            }
            printf("%d %d\n", N, N-1);
            printf("%d %d\n", 2*N, i);
        } else printf("No\n");
    } else {
        printf("Yes\n");
        for (int i=1; i<2*N; i++) {
            printf("%d %d\n", i, i+1);
        }
    }

    return 0;
}