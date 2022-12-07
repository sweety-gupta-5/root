#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string s, x;

    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            x += s[i];
    s = x;

    cin >> k;

    cout << "\nPlain text is: " << s << endl;
    cout << "key is: " << k << endl;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z')
            s[i] = (s[i] - 'a' + k + 26) % 26 + 'a';
        if (s[i] >= 'A' and s[i] <= 'Z')
            s[i] = (s[i] - 'A' + k + 26) % 26 + 'A';
    }

    cout << "\nCipher text is: " << s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z')
            s[i] = (s[i] - 'a' - k + 26) % 26 + 'a';
        if (s[i] >= 'A' and s[i] <= 'Z')
            s[i] = (s[i] - 'A' - k + 26) % 26 + 'A';

    }

    cout << "\n\nPlain text after decription is: " << s;

    return 0;
}