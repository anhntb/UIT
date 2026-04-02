int gcd(int x, int y, int z){
    int r, swap;

    if (x < 1 || y < 1 || z < 1){
        return -1;
    }

    if (x == 1 || y == 1 || z == 1){
        return 1;
    }

    if (x < y){
        swap = x;
        x = y;
        y = swap;
    }

    r = x % y;
    while (r != 0){
        x = y;
        y = r;
        r = x % y;
    }

    if (y < z){
        swap = y;
        y = z;
        z = swap;
    }

    r = y % z;
    while (r != 0){
        y = z;
        z = r;
        r = y % z;
    }

    return z;
}