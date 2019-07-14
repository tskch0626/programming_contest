#include<bits/stdc++.h>
#define MAX 100000

int n;
int a[MAX];

int main() {
    scanf("%d", &n);

    int a;
    scanf("%d", &a);
    int t;
    for (int i=0; i<n-1; i++) {
        scanf("%d", &t);
        a ^= t;
    }

    if (a==0) printf("Yes\n");
    else printf("No\n");
}