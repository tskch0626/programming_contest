#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, D;

    cin >> N >> D;

    D = 2*D + 1;

    int ans = N/D;
    if (N%D!=0) ans++;

    cout << ans << endl;

    return 0;
}