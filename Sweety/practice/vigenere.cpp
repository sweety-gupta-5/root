#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s, x = "", y = "", z, k;
    k = 3;
    cout << "Enter pt: ";
    // getline(cin, pt);

    getline(cin, s);
    cout << "\nEnter key: ";
    getline(cin, k);
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            z += s[i];
    s = z;
    for (int i = 0; i < s.length(); i++)
    {
        x += (((s[i] - 'a') + (k[i % k.length()] - 'a') + 26) % 26) + 'a';
    }
    cout << x;
    for (int i = 0; i < x.length(); i++)
    {
        y += (((x[i] - 'a') - (k[i % k.length()] - 'a') + 26) % 26) + 'a';
    }
    cout << "\n"
         << y;
    // for (int i = 0; i < x.length(); i++)
    // {
    //     y += ((x[i] - 'a' )- k + 26) % 26) + 'a';
    // }
    // cout << "\n"
    //      << y;
    return 0;
}