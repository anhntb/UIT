#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string n;
    cin >> n;

    char t;
    for(int i=0; i<n.length()-1; i++)
        for(int j=i+1; j<n.length(); j++)
            if(n[i] > n[j])
            {
                t=n[i];
                n[i]=n[j];
                n[j]=t;
            }

    while(n[0]=='0') n.erase(0,1);
    cout << n;

    return 0;
}
