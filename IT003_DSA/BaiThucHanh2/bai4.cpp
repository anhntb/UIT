#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;
    int z;
};

bool myFunction(Point a, Point b)
{
    if(a.x==b.x)
        if(a.y==b.y)
            return a.z<=b.z;
        else
            return a.y>=b.y;
    else
        return a.x<=b.x;
}

int main()
{
    int n;
    cin >> n;

    vector<Point> p(n);
    for(vector<Point>::iterator i = p.begin(); i<p.end(); i++)
        cin >> i->x >> i->y >> i->z;
    cout << endl;

    sort(p.begin(), p.end(), myFunction);

    for(vector<Point>::iterator i = p.begin(); i<p.end(); i++)
        cout << i->x << " " << i->y << " " << i->z << endl;

    return 0;
}
