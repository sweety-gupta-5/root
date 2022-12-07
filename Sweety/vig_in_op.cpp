#include <bits/stdc++.h>
using namespace std;

string encrypt(string s, string k)
{
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z')
            s[i] = (s[i] - 'a' + k[i % k.length()] - 'a' + 26) % 26 + 'a';
        if (s[i] >= 'A' and s[i] <= 'Z')
            s[i] = (s[i] - 'A' + k[i % k.length()] - 'a' + 26) % 26 + 'A';
    }
    ans = s;
    return ans;
}

string decrypt(string s, string k)
{
    string plainText;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z')
            s[i] = (s[i] - 'a' - (k[i % k.length()] - 'a') + 26) % 26 + 'a';
        if (s[i] >= 'A' and s[i] <= 'Z')
            s[i] = (s[i] - 'A' - (k[i % k.length()] - 'a') + 26) % 26 + 'A';
    }
    plainText = s;
    return plainText;
}

int main()
{
    int option;
    string s, x, k, ans;

    cout << "How do you want to give input?:\n1) Through terminal\n2) Through File\n";
    cin >> option;
    cout << "Enter key: ";
    cin >> k;
    switch (option)
    {
    case 1:
        cout << "Enter plainText: ";
        break;
    case 2:
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        break;
    }

    // getline(cin, s);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            x += s[i];
    s = x;

    cout << "\nPlain text is: " << s;
    cout << "\nKey is: " << k;
    s = encrypt(s, k);

    cout << "\nCipher text is: " << s;

    s = decrypt(s, k);

    cout << "\n\nPlain text after decryption is: " << s;

    return 0;
}