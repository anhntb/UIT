#include <iostream>

using namespace std;

int main()
{
    int max_x, max_y, max_z;
    max_x = (979-7-9)/2;
    max_y = (979-2-9)/7;
    max_z = (979-2-7)/9;

    cout << "Cac bo nghiem cua 2x + 7y + 9z = 979 (x,y,z > 0)\n";
    for(int x=1; x<=max_x; x++)
        for(int y=1; y<=max_y; y++)
            for(int z=1; z<=max_z; z++)
                if(2*x + 7*y + 9*z == 979)
                    cout << "x = " << x << "     y = " << y << "     z = " << z << endl;

    return 0;
}
