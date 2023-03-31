#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) \
  for (auto i : a) \
    cerr << i << " ";
#define nl << '\n'
#define sp << " " <<
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define ll long long int
#define debug2(n1, n2) \
  cerr << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#ifndef ONLINE_JUDGE
#define debug(n)  cerr << #n << " : ";_dprint(n); cerr nl;
#else
#define debug(n)
#endif
template <class T>
void _dprint(vector<T> a) { display(a) };
template <class T>
void _dprint(T a) {
  cerr << a << "\n";
}
int n, k;

void solve() {
  cin >> n >> k;
  vector<ll> a(n + 1, 0);
  for (ll i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  vector<ll> len;
  for (ll i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      len.push_back(1);
    }
    else
      (*len.rbegin())++;
  }
  vector<ll> freq(2 * n + 3, 0), pref(freq.size(), 0);
  for (auto& i : len) freq[i]++;
  for (ll i = 1; i < freq.size(); i++) {
    pref[i] += pref[i - 1] + freq[i];
  }
  debug(pref);
  ll x, left;
  for (ll i = 1; i <= n; i++) {
    ll cnt = 0;
    for (ll j = i; j <= n; j += i + 1) {
      cnt += (pref[j + i + 1] - pref[j]) * (1 + j / (i + 1));
    }
    if (cnt <= k) {
      x = i;
      left = k - cnt;
      break;
    }
  }
  debug(x);
  if (x == 1) {
    cout << n nl;
    return;
  }
  vector<pair<ll, ll>> h(len.size());
  priority_queue<pair<ll, ll>> p;
  for (ll i = 0;i < len.size();i++) {
    if (len[i] % (x + 1) != x) {
      ll k = (x - len[i] % (x + 1) - 1);
      h[i].first = max((len[i] / (x + 1)) - k, 0ll);
    }
    else {
      h[i].first = (len[i] / (x + 1)) + 1;
    }
    h[i].second = len[i];
    p.push(h[i]);
  }
  for (ll i = 0;i < left;i++) {
    auto ht = p.top();
    p.pop();
    ll l = ht.second - x;
    if (l % (x + 1) != x) {
      ll k = (x - l % (x + 1) - 1);
      ht.first = max((l / (x + 1)) - k, 0ll);
    }
    else {
      ht.first = l / (x + 1) +1;
    }
    p.push(ht);
  }

  ll ans = 0ll;
  for (ll i = 0ll;i < h.size();i++) {
    auto ht = p.top();
    p.pop();
    if (ht.first == 0ll) {
      ll z = x - 1;
      ll l = ht.second;
      ll r;
      if (l % (z + 1) != z) {
        ll k = (z - l % (z + 1) - 1);
        ans+=(r-k)*(x+1)*x/2 + (k+1)*(x-1)*x/2 + r;
      }
      else {
        r = (l / (z + 1)) + 1;
        ans+=(r+1)*(x+1)*x/2 + r;
      }
    }
    else {
      ll r = (ht.second - ht.first * (x + 1) + 1) / x;
      ans += ht.first * (x + 1) * x / 2 + r * (x - 1) * x / 2 + ht.first + r-1;
    }
  }
  cout << ans nl;
}

int main()
{
  fast_io;
#ifdef __linux__
  string path = "/mnt/3C401CB3401C75BC/CP/";
#elif _WIN32
  string path = "D:/CP/";
#endif
#ifndef ONLINE_JUDGE
  freopen((path + "input.txt").c_str(), "r", stdin);
  freopen((path + "output.txt").c_str(), "w", stdout);
  freopen((path + "error.txt").c_str(), "w", stderr);
#endif
  int t;
  cin >> t;
  while (t--)
    solve();
}
