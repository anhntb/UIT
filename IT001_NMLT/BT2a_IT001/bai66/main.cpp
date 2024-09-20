#include <iostream>
#include <math.h>

using namespace std;

float x, x1, x2;
int k(1); //kiểm tra số lượng nghiệm

void ptbac1(float a, float b)
{
    if(a==0)
    {
        cout << ((b!=0) ? "Vo nghiem" : "Vo so nghiem");
        exit(0);
    }
    else x = -b/a;
}

void ptbac2(float a, float b, float c)
{
    if(a==0) ptbac1(b,c);
    else
    {
        float delta = b*b - 4*a*c;
        if(delta<0)
        {
            cout << "Vo nghiem";
            exit(0);
        }
        if(delta==0) x = -b/(2*a);
        if(delta>0)
        {
            x1 = (-b+sqrt(delta))/(2*a);
            x2 = (-b-sqrt(delta))/(2*a);
            k = 2;
        }
    }
}

int main()
{
    float a,b,c;
    cin >> a >> b >> c;
    ptbac2(a,b,c);
    if(k==1) printf(x<0 ? "Vo nghiem" : x==0 ? "x = 0" : "x1 = %f\nx2 = %f", sqrt(x), -sqrt(x));
    else //k=2
    {
        //trường hợp 3 nghiệm
        if(x1==0)
        {
            printf(x2<0 ? "x = 0" : "x1 = 0\nx2 = %f\nx3 = %f", sqrt(x2), -sqrt(x2));
            exit(0);
        }
        if(x2==0)
        {
            printf(x1<0 ? "x = 0" : "x1 = 0\nx2 = %f\nx3 = %f", sqrt(x1), -sqrt(x1));
            exit(0);
        }
        //trường hợp 0,2,4 nghiệm
        if(x1<0 && x2<0)
        {
            cout << "Vo nghiem";
            exit(0);
        }
        if(x1>0 && x2>0) printf("x1 = %f\nx2 = %f\nx3 = %f\nx4 = %f", sqrt(x1), -sqrt(x1), sqrt(x2), -sqrt(x2));
        else if(x1<0) printf("x1 = %f\nx2 = %f", sqrt(x2), -sqrt(x2));
             else printf("x1 = %f\nx2 = %f", sqrt(x1), -sqrt(x1));
    }
    return 0;
}





















