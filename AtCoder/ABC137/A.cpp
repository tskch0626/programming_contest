#include<bits/stdc++.h>
using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    int ans = -300;

    ans = max(ans, A+B);
    ans = max(ans, A-B);
    ans = max(ans, A*B);

    cout << ans << endl;

    return 0;
}