#include <stdio.h>
#include <math.h>

// ---------- O(n^2) Approach ----------
long long sum_n2(int x, int n) {
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
        long long power = 1;
        for (int j = 0; j < i; j++) 
            power *= x;
        sum += power;
    }
    return sum;
}

// ---------- O(n) Approach ----------
long long sum_n(int x, int n) {
    long long sum = 1, term = 1;
    for (int i = 1; i <= n; i++) {
        term *= x;   // reuse power
        sum += term;
    }
    return sum;
}

// ---------- Fast Power (O(log n)) ----------
long long fast_pow(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

// ---------- O(log n) Approach ----------
long long sum_log(int x, int n) {
    if (x == 1) return n + 1;
    long long numerator = fast_pow(x, n+1) - 1;
    return numerator / (x - 1);
}

// ---------- O(1) Approach (using math.h pow) ----------
long long sum_const(int x, int n) {
    if (x == 1) return n + 1;
    return (pow(x, n+1) - 1) / (x - 1);
}

int main() {
    int x, n, choice;
    printf("Enter value of x and n: ");
    scanf("%d %d", &x, &n);

    printf("\nChoose method:\n");
    printf("1. O(n^2) method\n");
    printf("2. O(n)   method\n");
    printf("3. O(log n) method (fast exponentiation)\n");
    printf("4. O(1)   method (formula)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    long long result;
    switch(choice) {
        case 1: result = sum_n2(x, n); break;
        case 2: result = sum_n(x, n); break;
        case 3: result = sum_log(x, n); break;
        case 4: result = sum_const(x, n); break;
        default: 
            printf("Invalid choice!\n");
            return 0;
    }

    printf("Sum = %lld\n", result);
    return 0;
}
