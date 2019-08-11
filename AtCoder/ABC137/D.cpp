#include<bits/stdc++.h>
using namespace std;
#define MAX (int)1e+5+1
typedef long long ll;

int N, M;
pair<int, int> AB[MAX];
priority_queue<int> Q;

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        AB[i] = make_pair(a, b);
    }

    ll ans = 0;
    sort(AB, AB+N);
    int index = 0;

    for (int i=0; i<M; i++) {
        for (; index<N; index++) {
            if (AB[index].first==(i+1)) Q.push(AB[index].second);
            else break;
        }
        if (!Q.empty()) {
            ans += Q.top();
            Q.pop();
        }
    }

    printf("%lld\n", ans);

    return 0;
}