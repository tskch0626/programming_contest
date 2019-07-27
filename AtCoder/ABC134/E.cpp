#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

int A[MAX];
int N;

void solve() {
    multiset<int> M;

    for (int i=0; i<N; i++) {
        auto itr = M.lower_bound(A[i]);
        if (itr!=M.begin()) M.erase(--itr);
        M.insert(A[i]);
    }
    cout << M.size() << endl;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];

    solve();

    return 0;
}