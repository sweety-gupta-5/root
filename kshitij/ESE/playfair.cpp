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
    map<char, pair<int, int>> char_index;
    vector<vector<char>> mat(5, vector<char>(5, '%'));
    int i = 0, j = 0, l = 0;
    while (i < 5 and l < k.size())
    {
        if (k[l] == 'j')
            k[l] = 'i';
        if (char_index.find(k[l]) == char_index.end())
        {
            mat[i][j] = k[l];
            char_index[k[l]] = {i, j};
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
        l++;
    }
    for (char ch = 'a'; i < 5 and ch <= 'z'; ch++)
    {
        if (ch == 'j')
            ch++;
        if (char_index.find(ch) == char_index.end())
        {
            mat[i][j] = ch;
            char_index[ch] = {i, j};
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    cout << "\nPlayfair Matrix is: \n";
    for (int ii = 0; ii < 5; ii++)
    {
        for (int jj = 0; jj < 5; jj++)
        {
            cout << mat[ii][jj] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i < pt.size(); i++)
    {
        if (i % 2 and pt[i - 1] == pt[i])
        {
            pt.insert(i, "x");
        }
    }
    if (pt.size() % 2)
        pt.push_back('z');
    for (int i = 1; i < pt.size(); i += 2)
    {
        int fi, fj, si, sj;
        fi = char_index[pt[i - 1]].first;
        fj = char_index[pt[i - 1]].second;
        si = char_index[pt[i]].first;
        sj = char_index[pt[i]].second;
        if (si == fi)
        {
            sj++;
            fj++;
            if (fj == 5)
                fj = 0;
            if (sj == 5)
                sj = 0;
            ct.push_back(mat[fi][fj]);
            ct.push_back(mat[si][sj]);
        }
        else if (sj == fj)
        {
            si++;
            fi++;
            if (fi == 5)
                fi = 0;
            if (si == 5)
                si = 0;
            ct.push_back(mat[fi][fj]);
            ct.push_back(mat[si][sj]);
        }
        else
        {
            ct.push_back(mat[fi][sj]);
            ct.push_back(mat[si][fj]);
        }
    }
    cout << "\nCipher text is: " << ct;
    pt = "";
    for (int i = 1; i < ct.size(); i += 2)
    {
        int fi, fj, si, sj;
        fi = char_index[ct[i - 1]].first;
        fj = char_index[ct[i - 1]].second;
        si = char_index[ct[i]].first;
        sj = char_index[ct[i]].second;
        if (si == fi)
        {
            sj--;
            fj--;
            if (fj == -1)
                fj = 4;
            if (sj == -1)
                sj = 4;
            pt.push_back(mat[fi][fj]);
            pt.push_back(mat[si][sj]);
        }
        else if (sj == fj)
        {
            si--;
            fi--;
            if (fi == -1)
                fi = 4;
            if (si == -1)
                si = 4;
            pt.push_back(mat[fi][fj]);
            pt.push_back(mat[si][sj]);
        }
        else
        {
            pt.push_back(mat[fi][sj]);
            pt.push_back(mat[si][fj]);
        }
    }
    if (pt.back() == 'z')
        pt.pop_back();
    for (int i = 2; i < pt.size(); i++)
    {
        if (pt[i - 2] == pt[i] and pt[i - 1] == 'x')
        {
            pt.erase(i - 1, 1);
        }
    }
    cout << "\n\nPlain text after decription is: " << pt;
    return 0;
}