#ifndef COLOC_CP_TEMPLATE
#define COLOC_CP_TEMPLATE
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define SP << " " <<
#define NL << "\n"
#define FAST_IO                                                                \
  cin.tie(NULL);                                                               \
  ios_base::sync_with_stdio(false);

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const double EPS = 1e-9;
#ifdef CCMOD
const ll MOD = 1'000'000'007LL;
#else
const ll MOD = 998'244'353LL;
#endif

#define FOR(i, b, e) for (ll i = ll(b); (i) < ll(e); (i)++)
#define REP(i, b, e) for (ll i = ll(b); (i) <= ll(e); (i)++)
#define F0R(i, e) FOR(i, 0, (e))
#define SZ(a) ll((a).size())
#define ALL(c) (c).begin(), (c).end()
#define TR(c, i)                                                               \
  for (decltype((c).begin()) i = (c).begin(); (i) != (c).end(); (i)++)
#define PRESENT(c, x) ((c).find(x) != (c).end())
#define CPRESENT(c, x) (find(ALL(c), (x)) != (c).end())
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define SCV(c) TR((c), it) cin >> *it;

#endif

const ll SEG_INVALID = -1'000'000'000'000'000'000LL;

class SegObj {
private:
  ll v;

public:
  SegObj() : v{SEG_INVALID} {}
  SegObj(ll _v) : v{_v} {}

  operator ll() const { return v; }
  bool valid() const { return v != SEG_INVALID; }
};

enum lazy_type {
  LAZY_NONE,
  LAZY_REPLACE,
  LAZY_INCREASE,
};

class LazyObj {
public:
  lazy_type type;
  ll val;

  LazyObj() : type{LAZY_NONE} {}
};

class SegmentTree {
private:
  vi A;
  vector<SegObj> st;
  vector<LazyObj> lazy;

  ll left(ll x) { return x << 1ll; }
  ll right(ll x) { return (x << 1ll) | 1ll; }

  SegObj prop(ll i) { return A[i]; }

  SegObj combine(SegObj p1, SegObj p2) {
    if (!p1.valid())
      return p2;
    if (!p2.valid())
      return p1;

    if (p1 <= p2)
      return p1;
    return p2;
  }

  void resolve(ll p, ll L, ll R) {
    switch (lazy[p].type) {
    case LAZY_NONE:
      break;

    case LAZY_REPLACE:
      st[p] = lazy[p].val;
      if (L == R) {
        A[L] = lazy[p].val;
      } else {
        lazy[left(p)] = lazy[p];
        lazy[right(p)] = lazy[p];
      }
      break;

    case LAZY_INCREASE:
      st[p] = st[p] + lazy[p].val;
      if (L == R) {
        A[L] += lazy[p].val;
      } else {
        switch (lazy[left(p)].type) {
        case LAZY_NONE:
          lazy[left(p)] = lazy[p];
          break;
        case LAZY_REPLACE:
        case LAZY_INCREASE:
          lazy[left(p)].val += lazy[p].val;
          break;
        }

        switch (lazy[right(p)].type) {
        case LAZY_NONE:
          lazy[right(p)] = lazy[p];
          break;
        case LAZY_REPLACE:
        case LAZY_INCREASE:
          lazy[right(p)].val += lazy[p].val;
          break;
        }
      }
      break;
    }

    lazy[p].type = LAZY_NONE;
  }

  void build(ll p, ll L, ll R) {
    if (L == R) {
      st[p] = prop(L);
      return;
    }

    ll mid = (L + R) / 2ll;
    build(left(p), L, mid);
    build(right(p), mid + 1ll, R);
    st[p] = combine(st[left(p)], st[right(p)]);
  }

  SegObj rmq(ll p, ll L, ll R, ll i, ll j) {
    resolve(p, L, R);
    if (i > R || j < L) {
      return SegObj();
    }
    if (L >= i && R <= j) {
      return st[p];
    }

    ll mid = (L + R) / 2ll;
    SegObj p1 = rmq(left(p), L, mid, i, j);
    SegObj p2 = rmq(right(p), mid + 1ll, R, i, j);
    return combine(p1, p2);
  }

  void range_update(ll p, ll L, ll R, ll i, ll j, LazyObj up) {
    resolve(p, L, R);
    if (i > R || j < L)
      return;
    if (L >= i && R <= j) {
      lazy[p] = up;
      resolve(p, L, R);
      return;
    }

    ll mid = (L + R) / 2ll;
    range_update(left(p), L, mid, i, j, up);
    range_update(right(p), mid + 1ll, R, i, j, up);
    st[p] = combine(st[left(p)], st[right(p)]);
  }

public:
  SegmentTree(const vi &arr) : A(arr), st(4ll * SZ(arr)), lazy(4ll * SZ(arr)) {
    build(1ll, 0ll, SZ(A) - 1ll);
  }

  ll rmq(ll i, ll j) { return rmq(1ll, 0ll, SZ(A) - 1ll, i, j); }

  void range_update(ll i, ll j, LazyObj up) {
    range_update(1ll, 0ll, SZ(A) - 1ll, i, j, up);
  }
};

int main() {
  ll n, m;
   FAST_IO;
  cin >> n;
  vi a(n);
  SCV(a);
  SegmentTree seg(a);

  cin >> m;
  string str;
  getline(cin, str);
  while (m--) {
    getline(cin, str);
    stringstream ss(str);
    ll temp;
    vi tmp;
    while (ss >> temp)
      tmp.push_back(temp);

    if (SZ(tmp) == 2ll) {
      ll lf = tmp[0], rg = tmp[1];
      if (lf <= rg) {
        cout << seg.rmq(lf, rg) NL;
      } else {
        ll r1 = seg.rmq(0ll, rg);
        ll r2 = seg.rmq(lf, n - 1ll);
        cout << min(r1, r2) NL;
      }
    } else {
      ll lf = tmp[0], rg = tmp[1], v = tmp[2];
      LazyObj up;
      up.type = LAZY_INCREASE;
      up.val = v;
      if (lf <= rg) {
        seg.range_update(lf, rg, up);
      } else {
        seg.range_update(0ll, rg, up);
        seg.range_update(lf, n - 1ll, up);
      }
    }
  }
}
