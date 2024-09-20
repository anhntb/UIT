#include <iostream>
#include <string>

using namespace std;

int main()
{
//Cach 1:
/*
    int h,p,s;
    scanf("%dh%dp%ds",&h,&p,&s);
    cout << h*3600 + p*60 + s << " giay";
*/

//Cach 2:
    int giay(0);
    string a;
    cin >> a;
    for(int i = a.find('h') - 1; i>=0; i--)
        giay = giay*10 + ((int) a[i] - 48)*3600;

    if(a[a.find('h')+2]=='p')
        giay += ((int) a[a.find('h')+1] - 48)*60;
    else
        giay += ((int) a[a.find('h')+1] - 48)*60*10 + ((int) a[a.find('h')+2] - 48)*60;

    if(a[a.length()-3]=='p')
        giay += (int) a[a.length()-2] - 48;
    else
        giay += ((int) a[a.length()-3] - 48)*10 + (int) a[a.length()-2] - 48;
    cout << giay << " giay";
    return 0;
}
