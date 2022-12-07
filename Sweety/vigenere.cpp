#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, x, k;
    cout << "Enter plain text: ";

    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            x += s[i];
    s = x;

    cout << "\nEnter key: ";
    cin >> k;

    cout << "\nPlain text is: " << s;
    cout << "\nKey is: " << k;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z')
            s[i] = (s[i] - 'a' + k[i % k.length()] - 'a' + 26) % 26 + 'a';
        if (s[i] >= 'A' and s[i] <= 'Z')
            s[i] = (s[i] - 'A' + k[i % k.length()] - 'a' + 26) % 26 + 'A';
    }

    cout << "\nCipher text is: " << s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z')
            s[i] = (s[i] - 'a' - (k[i % k.length()] - 'a') + 26) % 26 + 'a';
        if (s[i] >= 'A' and s[i] <= 'Z')
            s[i] = (s[i] - 'A' - (k[i % k.length()] - 'a') + 26) % 26 + 'A';
    }

    cout << "\n\nPlain text after decription is: " << s;

    return 0;
}