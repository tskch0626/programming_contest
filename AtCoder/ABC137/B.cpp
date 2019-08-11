#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int K, X;

int main() {
    cin >> K >> X;

    int s, f;
    s = X-K+1;
    f = X+K-1;
    if (s<(-MAX)) s = -MAX;
    if (f>MAX) f = MAX;
    for (int i=s; i<=f; i++) printf("%d ", i);

    return 0;
}