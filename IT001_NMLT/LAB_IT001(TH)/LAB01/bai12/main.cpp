#include <iostream>
#include <time.h> //time(0), time_t

using namespace std;

//Random số thực
float randomR(int minN, int maxN)
{
    float r = (float)rand() / RAND_MAX; // r thuộc [0,1], RAND_MAX là giá trị lớn nhất của hàm rand()
    return minN + r*(maxN - minN);
}

//Random số nguyên
int randomZ(int minN, int maxN)
{
    return minN + rand()%(maxN - minN + 1);
}

int main()
{
    srand(time(0)); //random tại mọi thời điểm
    cout << "a) 0 -> 100\n+So thuc: " << randomR(0,100)
         << "\n+So nguyen: " << randomZ(0,100) << endl;
    cout << "\nb) 50 -> 99\n+So thuc: " << randomR(50,99)
         << "\n+So nguyen: " << randomZ(50,99) << endl;
    cout << "\nc) -39 -> 79\n+So thuc: " << randomR(-39,79)
         << "\n+So nguyen: " << randomZ(-39,79) << endl;
    cout << "\nd) -79 -> -39\n+So thuc: " << randomR(-79,-39)
         << "\n+So nguyen: " << randomZ(-79,-39) << endl;

    return 0;
}
