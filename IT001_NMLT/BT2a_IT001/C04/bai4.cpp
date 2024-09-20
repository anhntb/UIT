#include <iostream>

using namespace std;

int main()
{
    char a;
    cin >> a;
    if(a>='A' && a<='Z') a = tolower(a);
    else a = toupper(a);
    cout << a;
    return 0;
}
