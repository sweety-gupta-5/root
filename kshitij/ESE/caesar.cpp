#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    string s, x;
    cout << "Enter plain text" << endl;
    getline(cin, s);
    for (auto ch : s)
        if (ch != ' ')
            x += ch;
    s = x;
    cout << "Enter key" << endl;
    cin >> k;
    cout << "\nPlain text is: " << s << endl;
    cout << "key is: " << k << endl;
    for (auto &ch : s)
    {
        if (ch >= 'a' and ch <= 'z')
            ch = (ch - 'a' + k + 26) % 26 + 'a';
        else if (ch >= 'A' and ch <= 'Z')
            ch = (ch - 'A' + k + 26) % 26 + 'A';
        else
            ch = (ch - '0' + k + 10) % 10 + '0';
    }
    cout << "\nCipher text is: " << s;
    for (auto &ch : s)
    {
        if (ch >= 'a' and ch <= 'z')
            ch = (ch - 'a' - k + 26) % 26 + 'a';
        else if (ch >= 'A' and ch <= 'Z')
            ch = (ch - 'A' - k + 26) % 26 + 'A';
        else
            ch = (ch - '0' - k + 10) % 10 + '0';
    }
    cout << "\n\nPlain text after decription is: " << s;
    return 0;
}
