#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll L, R;

    scanf("%lld %lld", &L, &R);

    if ((R-L)/2019>=1) printf("0\n");
    else {
        int minv = 2019;
        for (ll l=L; l<R; l++) {
            for (ll r=l+1; r<=R; r++) {
                int tmp = (l*r)%2019;
                minv = min(tmp, minv);
            }
        }
        printf("%d\n", minv);
    }

    return 0;
}