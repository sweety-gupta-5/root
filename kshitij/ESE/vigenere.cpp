#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, x, k;
    cout << "Enter plain text" << endl;
    getline(cin, s);
    for (auto &ch:s)
        if (ch != ' ')
            x += ch;
    s = x;
    cout << "Enter key" << endl;
    cin >> k;
    cout << "\nPlain text is: " << s << endl;
    cout << "key is: " << k << endl;
    int j = 0;
    for (auto &ch:s)
    {
        if (ch >= 'a' and ch <= 'z')
            ch = (ch - 'a' + k[j] - 'a' + 26) % 26 + 'a';
        else if (ch >= 'A' and ch <= 'Z')
            ch = (ch - 'A' + k[j] - 'a' + 26) % 26 + 'A';
        else
            ch = (ch - '0' + k[j] - 'a' + 10) % 10 + '0';
        j++;
        if (j >= k.size())
            j = 0;
    }
    cout << "\nCipher text is: " << s;
    j = 0;
    for (auto &ch:s)
    {
        if (ch >= 'a' and ch <= 'z')
            ch = (ch - 'a' - (k[j] - 'a') + 26) % 26 + 'a';
        else if (ch >= 'A' and ch <= 'Z')
            ch = (ch - 'A' - (k[j] - 'a') + 26) % 26 + 'A';
        else
            ch = (ch - '0' - (k[j] - 'a') + 10) % 10 + '0';
        j++;
        if (j >= k.size())
            j = 0;
    }
    cout << "\n\nPlain text after decription is: " << s;
    return 0;
}