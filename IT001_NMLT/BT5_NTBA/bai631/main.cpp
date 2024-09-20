/*
Cho n điểm không trùng nhau trong Oxy, 
tìm 1 đa giác lồi với các đỉnh là thuộc n điểm cho trước
sao cho đa giác lồi chứa các điểm còn lại.
*/

#include <iostream>
#include <cmath>
#define M 100

using namespace std;

struct DIEM
{
    float x, y;
};

void nhap(DIEM d[], int n)
{
    for(int i(0); i<n; i++)
    {
        cout << "+ d" << i+1 << "(x,y):" << endl;
        cout << "Nhap x: ";
        cin >> d[i].x;
        cout << "Nhap y: ";
        cin >> d[i].y;
        cout << endl;
    }
}

void xuat(DIEM d[], int n)
{
    cout << "------------------------------------------------------------------------------------------" << endl;
    for(int i(0); i<n; i++)
    {
        cout << "d" << i+1 << "(" << d[i].x << "," << d[i].y << ")     ";
    }
    cout << endl << endl;
}

struct dgThang
{
    float a,b;
};

bool dgT_theoy(DIEM a, DIEM b, dgThang &dt)
{
    if(a.x==b.x) return false; 

    dt.a = (a.y-b.y) / (a.x-b.x);
    dt.b = a.y - dt.a*a.x;
    return true; 
}

bool cungPhia(DIEM d[], int n, DIEM d1, DIEM d2)
{
    dgThang dt;
    bool check = dgT_theoy(d1,d2,dt);

    if(!check) 
    {
        bool ctrai(true), cphai(true);
        for(int i(0); i<n; i++)
        {
            if(d[i].x>d1.x)
            {
                ctrai = false;
                break;
            }
        }

        for(int i(0); i<n; i++)
        {
            if(d[i].x<d1.x)
            {
                cphai = false;
                break;
            }
        }

        return ctrai || cphai;
    }

    bool cduoi(true), ctren(true);
    for(int i(0); i<n; i++)
    {
        if((d[i].x==d1.x && d[i].y==d1.y) || (d[i].x==d2.x && d[i].y==d2.y))
            continue; 
        float dt_y = dt.a*d[i].x + dt.b; 
        if(d[i].y>dt_y)
        {
            cduoi = false;
            break;
        }
    }

    for(int i(0); i<n; i++)
    {
        if((d[i].x==d1.x && d[i].y==d1.y) || (d[i].x==d2.x && d[i].y==d2.y))
            continue;
        float dt_y = dt.a*d[i].x + dt.b; 
        if(d[i].y<dt_y)
        {
            ctren = false;
            break;
        }
    }

    return cduoi || ctren;
}

bool ThHang(DIEM d1, DIEM d2, DIEM d3)
{
    dgThang dt;
    bool check = dgT_theoy(d1,d2,dt);
    if(!check) 
        if(d3.x==d1.x)
            return true;
        else
            return false;
    
    dgThang tmp;
    bool flag = dgT_theoy(d1,d3,tmp);
    if(!flag) 
        return false;

    if(tmp.a==dt.a && tmp.b==dt.b)
        return true;
    
    return false;
}

bool dagiac(DIEM d[], int n, DIEM dgl[], int &sl)
{
    DIEM tmp[M];
    for(int i(0); i<n; i++)
    {
        tmp[i]=d[i];
    }

    for(int i(0); i<n-1; i++)
    {
        for(int j(i+1); j<n; j++)
        {
            if(tmp[i].y==tmp[j].y && tmp[i].x<tmp[j].x)
                swap(tmp[i],tmp[j]);
            if(tmp[i].y<tmp[j].y)
                swap(tmp[i],tmp[j]);
        }
    }

    int mark[M] = {0}; 
    for(int a(0); a<n-2; a++)
    {
        for(int b(a+1); b<n-1; b++)
        {
            for(int c(b+1); c<n; c++)
            {
                if(ThHang(tmp[a],tmp[b],tmp[c]))
                {
                    mark[b]=1;
                    break;
                }
            }
        }
    }

    sl=1;
    dgl[0]=tmp[0];
    for(int i(0); i<n-1; i++)
    {
        if(mark[i]!=1)
            for(int j(i+1); j<n; j++)
            {
                if(mark[j]!=1)
                    if(cungPhia(d,n,tmp[i],tmp[j]))
                    {
                        dgl[sl] = tmp[j];
                        sl++;
                    }
            }
    }
    sl--; 

    return sl>2;
}

int main()
{
    int n;
    DIEM d[M];
    cout << "Nhap n (>=3):";
    cin >> n;
    nhap(d,n);
    xuat(d,n);

    int sl;
    DIEM dgl[M];
    bool flag = dagiac(d,n,dgl,sl);
    if(flag)
    {
        cout << "---------------------------------CAC DINH CUA DA GIAC LOI---------------------------------" << endl;
        xuat(dgl,sl);
    }
    else 
        cout << "Khong ton tai da giac loi thoa yeu cau (*cac diem la 1 duong thang)" << endl;

    return 0;
}