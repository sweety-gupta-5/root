#include <bits/stdc++.h>
using namespace std;


int main()
{

    string s, org;
    cout << "Enter Cipher text" << endl;
    getline(cin, s);

    string x;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            x += s[i];
    s = x;

    int k = 0;

    cout << "\nCipher text is: " << s << endl << endl;

    org = s;
    for (int k = 0; k < 26; k++)
    {
        cout << "Keep Key as: " << k << endl;
        s = org;
        for (int i = 0; i < s.length(); i++)
        {

            int val = s[i] - 'a';
            val = (val - k + 26) % 26;
            char ch = 'a' + val;
            s[i] = ch;
        }
        cout << s << endl << endl;
    }

    return 0;
}