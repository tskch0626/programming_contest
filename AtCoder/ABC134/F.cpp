#include<stdio.h>
using namespace std;
typedef long long ll;

int n, m;
ll dp[51][51][51*51];
const ll p = 1000000007;

int main() {
    scanf("%d %d", &n, &m);

    if (m%2==1) {
        printf("0");
        return 0;
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<i; j++) {
            for (int k=0; k<=i*i; k++) dp[i][j][k] = 0;
        }
    }

    dp[0][0][0] = 1;

    for (int i=1; i<=n; i++) {
        for (int j=0; j<i; j++) {
            for (int k=0; k<=i*i; k++) {
                ll tmp = dp[i-1][j][k];
                dp[i][j+1][k+j+1] = (dp[i][j+1][k+j+1]+tmp) % p;
                dp[i][j][k+j] = (dp[i][j][k+j]+(2*j+1)*tmp) % p;
                if (j>=1) dp[i][j-1][k+j-1] = (dp[i][j-1][k+j-1]+j*j*tmp) % p;
            }
        }
    }

    printf("%lld", dp[n][0][m/2]);

    return 0;
}