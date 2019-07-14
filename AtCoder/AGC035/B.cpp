#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int N, M;
vector<int> T[MAX+1];
vector<int> A[MAX+1];
vector<int> B[MAX+1];
int num[MAX+1];
int color[MAX+1];

void initialize() {
    for (int i=1; i<=N; i++) {
        color[i] = WHITE;
        num[i] = 0;
    }

    queue<int> Q;
    int n = 1;
    color[n] = GRAY;
    Q.push(n);

    while(!Q.empty()) {
        n = Q.front();
        Q.pop();
        color[n] = BLACK;

        for (int i=0; i<T[n].size(); i++) {
            int c = T[n][i];
            if (color[c]==WHITE) {
                num[n]++;
                Q.push(c);
                color[c] = GRAY;
                A[n].push_back(c);
            }
        }
    }
}

void dps(int n) {
    int tmp = 0;
    for (int i=0; i<A[n].size(); i++) {
        int c = A[n][i];
        if (num[n]%2==1) {
            if (num[c]%2==1) {
                B[c].push_back(n);
                num[n]--;
                num[c]++;
            } else {
                B[n].push_back(c);
            }
        } else {
            if (num[c]%2==1) {
                for (int j=0; j<T[c].size(); j++) {
                    int t = T[c][j];
                    if (num[t]%2==1) {
                        if (num[c]<num[t]) swap(c,t);
                        B[t].push_back(c);
                        num[t]++;
                        num[c]--;
                        break;
                    }
                }
            }
        }
        dps(c);
    }
}

void solve() {
    initialize();
    dps(1);

    bool ans = true;
    for (int i=1; i<=N; i++) ans &= (num[i]%2==0);

    if (ans) {
        for (int i=1; i<=N; i++) {
            for (int j=0; j<B[i].size(); j++) {
                printf("%d %d\n", i, B[i][j]);
            }
        }
    } else printf("-1\n");
}

int main() {
    scanf("%d%d", &N, &M);

    int a, b;
    for (int i=0; i<M; i++) {
        scanf("%d%d", &a, &b);
        T[a].push_back(b);
        T[b].push_back(a);
    }

    solve();

    return 0;
}