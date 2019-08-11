#include<bits/stdc++.h>
using namespace std;
#define MAX 3000

int p;
int b[MAX];
int upstairs[MAX];
int inv_upstairs[MAX];

int power(int m, int n) {
    if (n==0) return 1;
    else if (n==1) return m;
    else {
        if (n%2==0) return (power((m*m)%p, n/2))%p;
        else return (m*power((m*m)%p, (n-1)/2))%p;
    }
}

int combination(int n, int k) {
    return (((upstairs[p-1]*inv_upstairs[k])%p)*inv_upstairs[p-1-k])%p;
}

int main() {
    int a;
    cin >> p;

    for (int i=0; i<p; i++) {
        b[i] = 0;
        if (i==0) upstairs[i] = 1;
        else upstairs[i] = (upstairs[i-1]*i)%p;
        inv_upstairs[i] = power(upstairs[i], p-2);
    }

    for (int i=0; i<p; i++) {
        cin >> a;
        if (a==1) {
            b[0] = (b[0] + 1) % p;
            b[p-1]--;
            for (int j=0; j<p-1; j++) {
                b[j] = (b[j] - power(-i, p-1-j)*combination(p-1, j))%p;
            }
        }
    }

    for (int i=0; i<p; i++) {
        if (b[i]>=0) {
            printf("%d ", b[i]%p);
        } else {
            while (b[i]<0) b[i] += p;
            printf("%d ", b[i]);
        }
    }

    return 0;

}