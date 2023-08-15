#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
bitset<N> mat[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, x, i, j;cin >> n;
    vector<vector<int>> pref(n, vector<int>(n));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> pref[i][j];
            pref[i][j]--;
            mat[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        mat[i][i] = 1;
        for (int j = 0; i != pref[i][j]; j++)
        {
            mat[i][pref[i][j]] = 1;
        }
    }

    for (int k = 0;k < n;++k)
    {
        for (int i = 0;i < n;++i)
        {
            if (mat[i][k])
            {
                mat[i] = mat[i] | mat[k];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < n; j++)
        {
            if (mat[pref[i][j]][i])
            {
                cout << (pref[i][j] + 1) << endl;
                break;
            }
        }
    }
}