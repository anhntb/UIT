#include <iostream>
#include <cmath>
#define PI 3.14

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(double xo=0, double yo=0) : x(xo), y(yo) {}

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    void setX(double xo)
    {
        x = xo;
    }

    void setY(double yo)
    {
        y = yo;
    }

    void tinhTien(double a, double b)
    {
        x += a;
        y += b;
    }

    void quayTamO(double alpha)
    {
        alpha = alpha*PI/180;
        double tmp = x;
        x = tmp*cos(alpha) - y*sin(alpha);
        y = tmp*sin(alpha) + y*cos(alpha);
    }

    friend ostream& operator << (ostream &out, const Point &a)
    {
        out << "(" << a.x << ", " << a.y << ")";
        return out;
    }

    friend istream& operator >> (istream &inp, Point &a)
    {
        inp >> a.x >> a.y;
        return inp;
    }
};

ostream& operator << (ostream&, const Point&);
istream& operator >> (istream&, Point&);

class Triangle
{
private:
    Point A;
    Point B;
    Point C;

public:
    Triangle(Point a=0, Point b=0, Point c=0) : A(a), B(b), C(c) {}

    bool isTriangle() const
    {
        double ABx = B.getX() - A.getX();
        double ABy = B.getY() - A.getY();

        double ACx = C.getX() - A.getX();
        double ACy = C.getY() - A.getY();

        if(ABx*ACy == ABy*ACx) 
            return false;
        return true;
    }

    void tinhTien(double a, double b)
    {
        A.tinhTien(a, b);
        B.tinhTien(a, b);
        C.tinhTien(a, b);
    }

    void quayTamO(double alpha)
    {
        A.quayTamO(alpha);
        B.quayTamO(alpha);
        C.quayTamO(alpha);
    }

    Point getG()
    {
        Point G;
        G.setX((A.getX()+B.getX()+C.getX())/3);
        G.setY((A.getY()+B.getY()+C.getY())/3);
        return G;
    }

    void phongTo(double k)
    {
        if(k==1) return;
        A.setX(A.getX()*k);
        A.setY(A.getY()*k);

        B.setX(B.getX()*k);
        B.setY(B.getY()*k);

        C.setX(C.getX()*k);
        C.setY(C.getY()*k);
    }

    void thuNho(double k)
    {
        if(k==1) return;
        A.setX(A.getX()/k);
        A.setY(A.getY()/k);

        B.setX(B.getX()/k);
        B.setY(B.getY()/k);

        C.setX(C.getX()/k);
        C.setY(C.getY()/k);
    }

    friend ostream& operator << (ostream &out, const Triangle &a)
    {
        out << "(" << a.A << ", " << a.B << ", " << a.C << ")";
        return out;
    }

    friend istream& operator >> (istream &inp, Triangle &a)
    {
        inp >> a.A >> a.B >> a.C;
        return inp;
    }
};

ostream& operator << (ostream&, const Triangle&);
istream& operator >> (istream&, Triangle&);

int main()
{
    Triangle a;
    cout << "Nhap tam giac a: ";
    cin >> a;
    cout << "a" << a << endl;

    return 0;
}
