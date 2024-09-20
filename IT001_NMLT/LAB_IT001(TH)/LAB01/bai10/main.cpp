#include <iostream>

using namespace std;

int main()
{
    int soxe, t_soxe(0);
    cout << "So xe cua ban: ";
    cin >> soxe;
    while(soxe > 0)
    {
        t_soxe += soxe%10;
        soxe /=10;
    }
    cout << "So nut: " << t_soxe%10;
    return 0;
}
