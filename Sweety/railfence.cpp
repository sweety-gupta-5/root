#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pt, x, ct;
    getline(cin, pt);
    for (int i = 0; i < pt.length(); i++)
        if (pt[i] != ' ')
            x += pt[i];
    pt = x;

    int n;
    cin >> n;
    int m = pt.size();
    int div = 2 * (n - 1);
    int bogus = 0;
    if (m % div > 0)bogus = div - (m % div);
    while (bogus > 0) {
        pt += 'z';
        bogus--;
    }
    cout << "Plain text is: " << pt << endl;
    cout << "depth is: " << n << endl;
    m = pt.size();
    vector<vector<char>> mat(n, vector<char>(m, '#'));
    int i = 0, j = 0, l = 0, inc = 1;

    while (l < pt.size()) {
        mat[i][j] = pt[l];
        i += inc; j++;
        if (n == 1)i = 0;
        if (i == n - 1) {
            inc = -1;
        }
        if (i == 0) {
            inc = 1;
        }
        l++;
    }
    cout << "\nColumnar Matrix is: \n";
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
            if (mat[ii][jj] != '#')ct += mat[ii][jj];
            cout << mat[ii][jj] << " ";
        }
        cout << "\n";
    }

    cout << "\nCipher text is: " << ct << "\n";


    return 0;
}
