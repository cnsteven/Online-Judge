#include <stdio.h>

int Factorial(const int N);

int main() {
    int N, NF;

    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)
        printf("%d! = %d\n", N, NF);
    else
        printf("Invalid input\n");

    return 0;
}

int Factorial(const int N) {
    if (N < 0)
        return 0;
    int ans = 1, i;
    for (i = 2; i <= N; i++)
        ans *= i;
    return ans;
}