#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char t;
    cin >> t;

    if(t>='A' && t<='Z') cout << (char)tolower(t);
    else cout << (char)toupper(t);

    return 0;
}
