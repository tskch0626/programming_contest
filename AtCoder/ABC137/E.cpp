#include<bits/stdc++.h>
using namespace std;
#define MAXM 5000
#define MAXN 2501
#define INF (int)1e+9
typedef long long ll;

int N, M, P;
vector<pair<int, int>> adj[MAXN];
ll dist[MAXN];
bool update[MAXN];
bool color[MAXN];

void dijkstra() {
    for (int i=1; i<=N; i++) {
        dist[i] = -INF;
        update[i] = false;
    }
    dist[1] = 0;
    for (int i=1; i<=N; i++) {
        for (int n=1; n<=N; n++) {
            for (int j=0; j<adj[n].size(); j++) {
                int from = n;
                int to = adj[n][j].first;
                int w = adj[n][j].second;
                if (dist[from] != -INF && dist[to]<dist[from]+w) {
                    dist[to] = dist[from] + w;
                    if (i==N) update[to] = true;
                }
            }
        }
    }
}

bool bps(int node) {
    for (int i=1; i<=N; i++) color[i] = false;
    color[node] = true;
    queue<int> Q;
    Q.push(node);
    while(!Q.empty()) {
        int from = Q.front();
        Q.pop();
        for (int j=0; j<adj[from].size(); j++) {
            int to = adj[from][j].first;
            if (to==N) return true;
            else if (color[to]==false) {
                Q.push(to);
                color[to] = true;
            }
        }
    }
    return false;
}

void solve() {
    dijkstra();

    if (update[N]) {
        cout << -1 << endl;
        return;
    }
    for (int i=1; i<N; i++) {
        if (update[i]) {
            if (bps(i)) {
                cout << -1 << endl;
                return;
            }
        }
    }

    if (dist[N]<0) cout << 0 << endl;
    else cout << dist[N] << endl;
}

int main() {
    cin >> N >> M >> P;
    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c-P));
    }

    solve();

    return 0;
}