#include <stdio.h>

void prefix_sum(int *a, int *b, int *c) {
    // implement me   
    *c = *c + *b + *a;
    *b = *b + *a;
}


int main() {
    int a = 1;
    int b = 2;
    int c = 3;

    prefix_sum(&a, &b, &c);

    printf("a: %d\n", a); // Expected output: 1
    printf("b: %d\n", b); // Expected output: 3
    printf("c: %d\n", c); // Expected output: 6

    return 0;
}
