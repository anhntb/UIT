#include <iostream>
#include <cctype> //toupper()/tolower()

using namespace std;

int main()
{
    char x;
    cin >> x;
    cout << (char)toupper(x); //tolower() để trả về chữ thường
    return 0;
}
