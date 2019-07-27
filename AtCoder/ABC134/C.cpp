#include<bits/stdc++.h>
using namespace std;
#define MAX 200000

int main() {
    int N, A[MAX], FA, SA;

    FA = SA = 0;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> A[i];
        if (A[i] > FA) {
            SA = FA;
            FA = A[i];
        } else if (A[i] > SA) SA = A[i];
    }

    for (int i=0; i<N; i++) {
        if (A[i] < FA) cout << FA << endl;
        else cout << SA << endl;
    }

    return 0;
}