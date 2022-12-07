#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pt, x, k, ct;
    getline(cin, pt);
    //removing the spaces
    for (int i = 0; i < pt.length(); i++)
        if (pt[i] != ' ')
            x += pt[i];
    pt = x;

    cin >> k;
    cout << "Plain text is: " << pt << endl;
    cout << "key is: " << k << endl;
    int m = k.size(); //no. of columns
    int n = pt.size() / m + (pt.size() % m != 0); //no. of rows
    x = k;
    sort(x.begin(), x.end()); //sorting the key
    map<char, int> ma;
    for (int ii = 0; ii < m; ii++) {
        ma[k[ii]] = ii;
    }

//making a matrix and filling a plain text char row-wise
    vector<vector<char>> mat(n, vector<char>(m, '#'));
    int i = 0, j = 0, l = 0;
    while (i < n and l < pt.size()) {
        mat[i][j] = pt[l];
        j++;
        if (j == m) {
            i++; j = 0;
        }
        l++;
    }

    cout << "\nColumnar Matrix is: \n";
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
            cout << mat[ii][jj] << " ";
        }
        cout << "\n";
    }
//getting a index of letter/(column no. to read first) using a sorted key
    for (auto ch : x) {
        int jj = ma[ch];
        for (int ii = 0; ii < n and mat[ii][jj] != '#'; ii++) {
            ct += mat[ii][jj];
        }
    }

    cout << "\nCipher text is: " << ct;

    int rem = ct.size() % m; //finding no. of column field to be filled in last row
    pt = "";
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
            mat[ii][jj] = '#';
        }
    }

    l = 0;
    for (auto ch : x) {
        int jj = ma[ch];
        int cnt = (jj < rem) ? n : n - 1; //finding no. of row to be filled of that column no.
        for (int ii = 0; ii < n and cnt>0 and l < ct.size(); ii++) {
            mat[ii][jj] = ct[l];
            cnt--;
            l++;
        }
    }

    cout << "\nColumnar Matrix is: \n";
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
            if (mat[ii][jj] != '#')pt += mat[ii][jj];
            cout << mat[ii][jj] << " ";
        }
        cout << "\n";
    }

    cout << "\n\nPlain text after decryption is: " << pt;

    return 0;
}