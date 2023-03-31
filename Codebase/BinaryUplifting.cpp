
class binruplift {
public:
    int n;
    vector<vector<int>> anc;
    vector<int> decHead;
    vector<int> height;
    int sz;
    binruplift(int n, vector<int> p):decHead(p), n(n) {
        height.resize(n + 1, -1);
        anc_precomp(p);
        sz = anc[0].size() - 1;
        height[0] = 0;
        for (int i = 1;i <= n;i++) {
            if (height[i] < 0)calht(i, height, p);
        }
    }
    binruplift() {}

    int kthancestor(int k, int x) {
        int j = 0;
        while (k > 0) {
            if (k & 1) x = anc[x][j];
            k >>= 1;
            j++;
        }
        return x;
    }

    void anc_precomp(vector<int>& p) {
        anc.resize(n + 1);
        anc[0].push_back(0);
        anc[1].push_back(0);
        for (int i = 2;i <= n;i++) {
            anc[i].push_back(p[i]);
        }
        int k = 2;
        for (int j = 1;k <= n;j++, k <<= 1) {
            anc[0].push_back(0);
            for (int i = 1;i <= n;i++) {
                anc[i].push_back(anc[anc[i][j - 1]][j - 1]);
            }
        }
    }
    int calht(int x, vector<int>& height, vector<int>& p) {
        if (height[x] >= 0) return height[x];
        height[x] = calht(p[x], height, p) + 1;
        return height[x];
    }
    int findlca(int a, int b) {
        if (height[a] > height[b]) swap(a, b);
        b = kthancestor(height[b] - height[a], b);
        return findlcarec(a, b, sz);
    }
    int findlcarec(int a, int b, int r) {
        if (a == b) return a;
        if (r == 0) return anc[a][0];
        if (anc[a][r - 1] == anc[b][r - 1]) {
            return findlcarec(a, b, r - 1);
        }
        else return findlcarec(anc[a][r - 1], anc[b][r - 1], r - 1);
    }
    int getDistance(int u, int v) {
        int l = findlca(u, v);
        return height[u] + height[v] - 2 * height[l];
    }
};
