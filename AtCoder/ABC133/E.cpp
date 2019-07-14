#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define MAX 100000
#define WHITE 0
#define BLACK 1
typedef long long ll;

int N, K;
int color[MAX+1];
vector<int> T[MAX+1];
queue<int> Q;
ll ans;

void dfs(int node, int depth, int cnum) {
    int c = cnum;
    if (depth >= 3) c += 2;
    else c += depth;

    ans *= K - c;
    ans %= 1000000007;
    color[node] = BLACK;

    int cnum_ = 0;
    for (auto itr = T[node].begin(); itr != T[node].end(); ++itr) {
        if (color[*itr]==WHITE) {
            dfs(*itr, depth+1, cnum_++);
        }
    }

}

void solve() {
    ans = 1;
    dfs(1, 0, 0);
    printf("%lld\n", ans);
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i=1; i<=N; i++) {
        color[i] = WHITE;
    }

    for (int i=0; i<N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        T[a].push_back(b);
        T[b].push_back(a);
    }

    solve();

    return 0;
}