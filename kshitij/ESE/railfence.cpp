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
	int k;
	cin >> k;
	int n = k;
	int m = pt.size();
	cout << "Plain text is: " << pt << endl;
	cout << "key is: " << k << endl;
	m = pt.size();
	vector<vector<char>> mat(n, vector<char>(m, '%'));
	int i = 0, j = 0, l = 0, inc = 1;
	while (l < pt.size())
	{
		mat[i][j] = pt[l];
		i += inc;
		j++;
		if (n == 1)
			i = 0;
		if (i == n - 1)
		{
			inc = -1;
		}
		if (i == 0)
		{
			inc = 1;
		}
		l++;
	}
	cout << "\nColumnar Matrix is: \n";
	for (int ii = 0; ii < n; ii++)
	{
		for (int jj = 0; jj < m; jj++)
		{
			if (mat[ii][jj] != '%')
				ct += mat[ii][jj];
			cout << mat[ii][jj] << " ";
		}
		cout << "\n";
	}
	cout << "\nCipher text is: " << ct << "\n";
	pt = "";
	for (int ii = 0; ii < n; ii++)
	{
		for (int jj = 0; jj < m; jj++)
		{
			mat[ii][jj] = '%';
		}
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
	i = 0, j = 0, l = 0, inc = 1;
	while (l < ct.size())
	{
		mat[i][j] = ct[l];
		i += inc;
		j++;
		if (n == 1)
			i = 0;
		if (i == n - 1)
		{
			inc = -1;
		}
		if (i == 0)
		{
			inc = 1;
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
	l = 0;
	for (int ii = 0; ii < n; ii++)
	{
		for (int jj = 0; jj < m; jj++)
		{
			if (mat[ii][jj] != '%')
				mat[ii][jj] = ct[l], l++;
		}
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
	i = 0, j = 0, l = 0, inc = 1;
	while (l < ct.size())
	{
		pt += mat[i][j];
		i += inc;
		j++;
		if (n == 1)
			i = 0;
		if (i == n - 1)
		{
			inc = -1;
		}
		if (i == 0)
		{
			inc = 1;
		}
		l++;
	}
	cout << "\n\nPlain text after decription is: " << pt << "\n";
	return 0;
}
