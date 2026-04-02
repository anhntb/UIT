#include <stdio.h>

int gcd(int x, int y, int z);

int main(void) {
    printf("gcd(1,1,1) = %d\n", gcd(1,1,1));
    printf("gcd(100,50,25) = %d\n", gcd(100,50,25));
    printf("gcd(6,3,90) = %d\n", gcd(6,3,90));
    return 0;
}
