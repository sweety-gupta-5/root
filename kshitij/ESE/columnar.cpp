#include <bits/stdc++.h>
using namespace std;
int main()
{
    string pt, x, k, ct;
    getline(cin, pt);
    for (int i = 0; i < pt.length(); i++)
        if (pt[i] != ' ')
            x += pt[i];
    pt = x;
    cin >> k;
    cout << "Plain text is: " << pt << endl;
    cout << "key is: " << k << endl;
    int m = k.size();
    int n = pt.size() / m + (pt.size() % m != 0);
    x = k;
    sort(x.begin(), x.end());
    map<char, int> ma;
    for (int ii = 0; ii < m; ii++)
    {
        ma[k[ii]] = ii;
    }
    vector<vector<char>> mat(n, vector<char>(m, '%'));
    int i = 0, j = 0, l = 0;
    while (i < n and l < pt.size())
    {
        mat[i][j] = pt[l];
        j++;
        if (j == m)
        {
            i++;
            j = 0;
        }
        l++;
    }
    cout << "\nColumnar Matrix is: \n";
    for (int ii = 0; ii < n; ii++)
    {
        for (int jj = 0; jj < m; jj++)
        {
            cout << mat[ii][jj] << " ";
        }
        cout << "\n";
    }
    for (auto ch : x)
    {
        int jj = ma[ch];
        for (int ii = 0; ii < n and mat[ii][jj] != '%'; ii++)
        {
            ct += mat[ii][jj];
        }
    }
    cout << "\nCipher text is: " << ct;
    int rem = ct.size() % m;
    pt = "";
    for (int ii = 0; ii < n; ii++)
    {
        for (int jj = 0; jj < m; jj++)
        {
            mat[ii][jj] = '%';
        }
    }
    l = 0;
    for (auto ch : x)
    {
        int jj = ma[ch];
        int cnt = (jj < rem) ? n : n - 1;
        for (int ii = 0; ii < n and cnt > 0 and l < ct.size(); ii++)
        {
            mat[ii][jj] = ct[l];
            cnt--;
            l++;
        }
    }
    cout << "\nColumnar Matrix is: \n";
    for (int ii = 0; ii < n; ii++)
    {
        for (int jj = 0; jj < m; jj++)
        {
            if (mat[ii][jj] != '%')
                pt += mat[ii][jj];
            cout << mat[ii][jj] << " ";
        }
        cout << "\n";
    }
    cout << "\n\nPlain text after decription is: " << pt;
    return 0;
}
