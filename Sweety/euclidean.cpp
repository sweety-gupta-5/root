#include <bits/stdc++.h>
using namespace std;

int main()
{

    int q, r1, r2, r;
    cin >> r1 >> r2;
    cout << r1 << " " << r2 << "\n";
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - r2 * q;
        r1 = r2;
        r2 = r;
    }
    cout << r1 << "\n";

    return 0;
}