#include<stdio.h>
#include<math.h>
using namespace std;
#define MAX 10
static const double Min = 0.000001;

int N, D;
int count;
int X[MAX][MAX];

int main() {
    scanf("%d %d", &N, &D);

    for (int i=0; i<N; i++) {
        for (int j=0; j<D; j++) {
            scanf("%d", &X[i][j]);
        }
    }

    count = 0;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            int sum = 0;
            for (int k=0; k<D; k++) {
                sum += (X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
            }
            double sum_sqrt = sqrt(sum);
            int intsum = sum_sqrt;
            if (sum_sqrt-Min<=intsum && intsum<=sum_sqrt+Min) count++;
        }
    }

    printf("%d\n", count);

    return 0;
}