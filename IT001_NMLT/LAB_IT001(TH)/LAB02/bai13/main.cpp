#include <iostream>

using namespace std;

float a,b,c;

void check()
{
    cout << "Nhap vao 3 canh cua tam giac: ";
    cin >> a >> b >> c;
    if(a<=0 || b<=0 || c<=0)
    {
        cout << "Error!!!\n\n";
        return check();
    }
}

int main()
{
    check();
    if(a+b>c && a+c>b && b+c>a)
    {
        if(a==b && b==c) cout << "Tam giac deu";
        else if( (a==b || a==c || b==c) && (a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b) )
                 cout << "Tam giac vuong can";
             else if(a==b || a==c || b==c) cout << "Tam giac can";
                  else if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b) cout << "Tam giac vuong";
                       else cout << "Tam giac thuong";
    }
    else cout << "Khong la tam giac";
    return 0;
}
