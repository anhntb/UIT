#include <iostream>
#include <ctime>

using namespace std;

int main()
{
/*
    Date và time hiện tại trong C++
    https://topdev.vn/blog/date-va-time-trong-c/
*/
    int namsinh;
    cin >> namsinh;
    time_t hientai = time(0);

//  int y_now = (localtime(&hientai)->tm_year + 1900);
    tm*ltm = localtime(&hientai);
    int y_now = ltm->tm_year + 1900;
    printf("Ban sinh nam %d vay ban %d tuoi.",namsinh,y_now - namsinh);
    return 0;
}
