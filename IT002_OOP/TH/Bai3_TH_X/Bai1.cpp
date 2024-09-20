#include <iostream>

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    void setX(double x)
    {
        this->x = x;
    }

    double getX() const
    {
        return x;
    }

    void setY(double y)
    {
        this->y = y;
    }

    double getY() const
    {
        return y;
    }

    Point transPoint(double xo, double yo = 0) const //translations
    {
        Point tmp;
        tmp.x = x + xo;
        tmp.y = y + yo;
        return tmp;
    }

    friend ostream& operator << (ostream &os, Point a)
    {
        os << "(" << a.x << ", " << a.y << ")";
        return os;
    }

    friend istream& operator >> (istream &is, Point &a)
    {
        double x, y;
        is >> a.x >> a.y;
        return is;
    }
};

ostream& operator << (ostream&, Point);
istream& operator >> (istream&, Point&);

int main()
{
    Point a(1,1), b ,c;
    cout << a << " " << Point(3,5) << endl;
    cin >> a >> b >> c;
    cout << a << endl << b << endl << c << endl;

    return 0;
}