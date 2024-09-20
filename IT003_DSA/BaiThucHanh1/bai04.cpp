#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool myFunction(Point a, Point b)
{
    if(a.x==b.x && a.y<b.y)
        return false;
    return a.x<=b.x;
}

int main()
{
    int n;
    cin >> n;

    vector<Point> p(n);
    for(vector<Point>::iterator i = p.begin(); i<p.end(); i++)
        cin >> i->x >> i->y;
    cout << endl;

    sort(p.begin(), p.end(), myFunction);

    for(vector<Point>::iterator i = p.begin(); i<p.end(); i++)
        cout << i->x << " " << i->y << endl;

    return 0;
}
