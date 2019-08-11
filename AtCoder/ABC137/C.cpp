#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX (int)1e+5

int N;
map<string, ll> a;

int main() {
    cin >> N;
    char s[15];

    for (int i=0; i<N; i++) {
        cin >> s;
        sort(s, s+10);
        if (a.find(s)==a.end()) a[s]=1;
        else a[s]++;
    }

    ll ans = 0;

    for (const auto x : a) {
        ans += (ll)x.second*(x.second-1)/2;
    }

    cout << ans << endl;
}