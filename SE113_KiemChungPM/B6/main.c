#include <stdio.h>

int gcd(int x, int y, int z);

int main(void) {
    int x, y, z;

    printf("Nhap 3 so nguyen duong x, y, z: ");
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        printf("Du lieu nhap khong hop le.\n");
        return 1;
    }

    printf("gcd(%d, %d, %d) = %d\n", x, y, z, gcd(x, y, z));
    return 0;
}