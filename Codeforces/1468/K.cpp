#include<bits/stdc++.h>
using namespace std;
#define nl << "\n"
#define sp << " " <<
#define spl << " "

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

map<char, pair<int, int>> dir = { {'L',{-1,0}},{'R',{1,0}},{'D',{0,-1}},{'U',{0,1}} };
void updPos(int& x, int& y, char c) {
    x += dir[c].first, y += dir[c].second;
}

bool solve() {
    string s;
    cin >> s;
    int flag = 0;
    int  x = 0, y = 0;
    for (int i = 0;i < s.length();i++) {
        updPos(x, y, s[i]);
        int tx = 0, ty = 0;
        for (int j = 0;j < s.length();j++) {
            int lastx = tx, lasty = ty;
            updPos(tx, ty, s[j]);
            if (tx == x && ty == y) {
                tx = lastx, ty = lasty;
            }
        }

        if (tx == 0 && ty == 0) {
            flag = 1;
            break;
        }
    }

    if (!flag)return false;
    cout << x sp y nl;
    return true;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        cout << (solve() ? "" : "0 0\n");
    }
}
