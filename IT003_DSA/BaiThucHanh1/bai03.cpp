#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> an;
    int tmp;
    for(int i(0); i<n; i++)
    {
        cin >> tmp;
        an.push_back(tmp);
    }
    cout << endl;

    sort(an.begin(), an.end());

    vector<int> aq;
    for(int i(0); i<q; i++)
    {
        cin >> tmp;
        aq.push_back(tmp);
    }
    cout << endl;

    for(int i(0); i<q; i++)
        cout << (binary_search(an.begin(), an.end(), aq.at(i)) ? "YES" : "NO") << endl;

    return 0;
}
