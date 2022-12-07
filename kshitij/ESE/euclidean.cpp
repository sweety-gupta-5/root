// Euclidean and Extended C++

#include <bits/stdc++.h>
using namespace std;

// Eucldiean
int gcd(int a, int b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q, r1, r2, r, s1 = 1, s2 = 0, s, t1 = 0, t2 = 1, t;
        cin >> r1 >> r2;
        cout << r1 << " " << r2 << "\n";
        cout << gcd(r1, r2) << "\n";
        cout << "q r1 r2 r s1 s2 s t1 t2 t\n";
        // Extended Euclidean
        while (r2 > 0) {
            cout << q << " " << r1 << " " << r2 << " " << r << " " << s1 << " " << s2 << " " << t1 << " " << t2 << "\n";
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
        cout << "Gcd: " << r1 << "\n s: " << s1 << "\n t: " << t1 << "\n";

    }
    return 0;
}
