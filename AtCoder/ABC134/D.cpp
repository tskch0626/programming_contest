#include<bits/stdc++.h>
using namespace std;
#define MAX 200000

int main() {
    int N, a[MAX], b[MAX];
    int count = 0;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> a[i];
    }

    for (int i=N; i>0; i--) {
        int A = a[i-1];
        if (i>N/2) b[i-1] = A;
        else {
            int sum = 0;
            for (int j=2; j*i<=N; j++) {
                sum += b[j*i-1];
            }
            sum %= 2;
            if (sum==A) b[i-1] = 0;
            else b[i-1] = 1;
        }
        count += b[i-1];
    }

    cout << count << endl;
    for (int i=0; i<N; i++) if (b[i]==1) printf("%d ", i+1);

    return 0;
}