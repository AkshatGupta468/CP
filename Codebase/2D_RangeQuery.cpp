#include <bits/stdc++.h>
using namespace std;
#define ll long long
class BIT_2D {
    int bit[1001][1001];
    int n;
    BIT_2D() {
        int q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '*') update(j, i, 1);
        }
        while (q--) {
            int t;
            cin >> t;
            if (t == 1) {
                int x, y;
                cin >> y >> x;
                if (query(x, y, x, y)) update(x, y, -1);
                else update(x, y, 1);
            }
            else {
                int y1, x1, y2, x2;
                cin >> y1 >> x1 >> y2 >> x2;
                cout << query(x1, y1, x2, y2) << '\n';
            }
        }
    }
    void update(int x, int y, int val) {
        for (; x <= n; x += (x & (-x))) {
            for (int i = y; i <= n; i += (i & (-i))) {
                bit[x][i] += val;
            }
        }
    }

    int query(int x1, int y1, int x2, int y2) {
        int ans = 0;
        for (int i = x2; i; i -= (i & (-i))) {
            for (int j = y2; j; j -= (j & (-j))) {
                ans += bit[i][j];
            }
        }
        for (int i = x2; i; i -= (i & (-i))) {
            for (int j = y1 - 1; j; j -= (j & (-j))) {
                ans -= bit[i][j];
            }
        }
        for (int i = x1 - 1; i; i -= (i & (-i))) {
            for (int j = y2; j; j -= (j & (-j))) {
                ans -= bit[i][j];
            }
        }
        for (int i = x1 - 1; i; i -= (i & (-i))) {
            for (int j = y1 - 1; j; j -= (j & (-j))) {
                ans += bit[i][j];
            }
        }
        return ans;
    }
};
struct node {
    ll val;
    node():val(1e9) {

    }
    node(ll val):val(val) {

    }
};

class SegmentTree2D {
    int n, m;
    node nullval;
    vector<vector<node>> t, a;
public:

    SegmentTree2D(int n, int m):n(n), m(m) {
        t.resize(4 * n, vector<node>(4 * m, nullval));
    }
    SegmentTree2D(vector<vector<node>>& a):n(a.size()), m(a[0].size()), a(a) {
        t.resize(4 * n, vector<node>(4 * m, nullval));
        build_x(1, 0, n - 1);
    }

    node combine(node lval, node rval) {
        return min(lval.val, rval.val);
    }

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry)
            if (lx == rx)
                t[vx][vy] = a[lx][ly];
            else
                t[vx][vy] = combine(t[vx * 2][vy], t[vx * 2 + 1][vy]);
        else {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy * 2, ly, my);
            build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
            t[vx][vy] = combine(t[vx][vy * 2], t[vx][vy * 2 + 1]);
        }
    }

    void build_x(int vx, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(vx * 2, lx, mx);
            build_x(vx * 2 + 1, mx + 1, rx);
        }
        build_y(vx, lx, rx, 1, 0, m - 1);
    }
    node query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry)
            return nullval;
        if (ly == tly && try_ == ry)
            return t[vx][vy];
        int tmy = (tly + try_) / 2;
        return combine(query_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy))
            , query_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
    }

    node query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx)
            return nullval;
        if (lx == tlx && trx == rx)
            return query_y(vx, 1, 0, m - 1, ly, ry);
        int tmx = (tlx + trx) / 2;
        return combine(query_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry)
            , query_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
    }
    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = new_val;
            else
                t[vx][vy] = combine(t[vx * 2][vy], t[vx * 2 + 1][vy]);
        }
        else {
            int my = (ly + ry) / 2;
            if (y <= my)
                update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
            else
                update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
            t[vx][vy] = combine(t[vx][vy * 2], t[vx][vy * 2 + 1]);
        }
    }

    void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx)
                update_x(vx * 2, lx, mx, x, y, new_val);
            else
                update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
        }
        update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
    }
};

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}