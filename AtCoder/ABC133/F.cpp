#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
#define MAX 100000
#define NIL -1
#define root 0
#define BITS 30

struct Edge {
    int n, c, d;
};

vector<Edge> T[MAX];
int N, Q;
vector<int> parent[BITS];
int depth[MAX];
int Distance[MAX];
map<int, int> cnum[MAX];
map<int, int> cdist[MAX];
int CNUM[MAX], CDIST[MAX];
vector<int> need[MAX];
int bitlen;

void make_tree(int node, int p, int dep) {
    depth[node] = dep;
    parent[0][node] = p;

    for (auto i=T[node].begin(); i!=T[node].end(); ++i) {
        if ((*i).n == p) continue;
        make_tree((*i).n, node, dep+1);
    }
}

void initialize() {
    bitlen = 1;
    while ((1<<bitlen) < N) bitlen++;
    for (int i=0; i<bitlen; i++) parent[i].resize(N);

    make_tree(0, 0, 0);

    for (int k=0; k<bitlen-1; k++) {
        for (int v=0; v<N; v++) {
            if (depth[v]==0) continue;
            if (parent[k][v] == 0) {
                parent[k+1][v] = 0;
            } else {
                parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k=0; k<bitlen; k++) {
        if ( ((depth[v]-depth[u]) >> k) & 1) v = parent[k][v];
    }
    if (u == v) return u;
    for (int k=bitlen-1; k>=0; k--) {
        if (parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
    /*
    while(depth[u]!=depth[v]) {
        u = parent[u];
    }
    while(u!=v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
    */
}

void dps(int r, int dist) {
    Distance[r] = dist;
    for (auto color = need[r].begin(); color!=need[r].end(); ++color) {
        cnum[r][*color] = CNUM[*color];
        cdist[r][*color] = CDIST[*color];
    }

    for (auto i=T[r].begin(); i!=T[r].end(); ++i) {
        if ((*i).n==parent[0][r]) continue;
        CNUM[(*i).c]++;
        CDIST[(*i).c] += (*i).d;
        dist += (*i).d;
        dps((*i).n, dist);
        CNUM[(*i).c]--;
        CDIST[(*i).c] -= (*i).d;
        dist -= (*i).d;
    }

}

int main() {
    scanf("%d%d", &N, &Q);

    for (int i=0; i<N; i++) {
        CNUM[i] = CDIST[i] = 0;
    }

    int a, b, c, d;
    for (int i=0; i<N-1; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a--, b--, c--;
        T[a].push_back({b, c, d});
        T[b].push_back({a, c, d});
    }

    initialize();

    int X[MAX], Y[MAX], U[MAX], V[MAX], L[MAX];
    for (int i=0; i<Q; i++) {
        scanf("%d%d%d%d", &X[i], &Y[i], &U[i], &V[i]);
        X[i]--, U[i]--, V[i]--;

        L[i] = lca(U[i], V[i]);

        need[U[i]].push_back(X[i]);
        need[V[i]].push_back(X[i]);
        need[L[i]].push_back(X[i]);
    }

    dps(root, 0);

    for (int i=0; i<Q; i++) {
        int x = X[i], y = Y[i], l = L[i], u = U[i], v = V[i];
        int dl = Distance[l] - cdist[l][x] + cnum[l][x]*y;
        int du = Distance[u] - cdist[u][x] + cnum[u][x]*y;
        int dv = Distance[v] - cdist[v][x] + cnum[v][x]*y;
        int d = du + dv - 2 * dl;
        printf("%d\n", d);
    }

    return 0;
}