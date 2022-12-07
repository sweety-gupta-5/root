#include <bits/stdc++.h>
using namespace std;

int main()
{

    int q, r1, r2, r, s1 = 1, s2 = 0, s, t1 = 0, t2 = 1, t;
    cin >> r1 >> r2;
    cout << r1 << " " << r2 << "\n";
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - r2 * q;
        r1 = r2;
        r2 = r;
        s = s1 - s2 * q;
        s1 = s2;
        s2 = s;
        t = t1 - t2 * q;
        t1 = t2;
        t2 = t;
    }
    cout << r1 << " " << s1 << " " << t1 << "\n";

    return 0;
}