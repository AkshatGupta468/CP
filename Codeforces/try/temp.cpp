#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl << '\n' 
#define sp << " " << 
#define all(x)         (x).begin(),(x).end()
#define debug(n) cout << #n << " : " << n << '\n'; 
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
const int M = 1e9+7;

int binaryexp(int a,int b, int rem){
    if(b==0) return 1;
    if(b%2==0){
        int t = binaryexp(a,b/2,rem);
        return (1ll*t*t) % rem;
    }
    int t = binaryexp(a,b/2,rem);
    t = (1ll * t * t) % rem;
    return (1ll * a * t) % rem;
}
const int N = 300040;
int fact[N]{},invfact[N]{};

void init(){
    int p = M;
    fact[0] = 1;
    int i;
    for(i =1;i<N;i++){
        fact[i] = (i * fact[i-1]) % p;
    }
    // i--;
    invfact[0] = 1;
    for(int i=1;i<N;i++){
        invfact[i] = binaryexp(fact[i],p-2,p);
    }
}

int ncr(int n, int r){
    if(r>n || n<0 || r<0 ) return 0;
    if(n==r) return 1;
    int z = ((invfact[r]) * (invfact[n-r])) % M;
    z *= fact[n];
    z %= M;
    return z;
}

void solve(){
    int n,m,k; cin >> n >> m >> k;
    int a[n+k+5]{};
    for(int i=0;i<n;i++){
        int x; cin >> x;
        a[x]++;
    }
    for(int i=1;i<=n+k+1;i++){
        a[i] += a[i-1];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int sum = a[i+k] - a[i-1];
        int sum2 = a[i+k] - a[i];
        // debug2(sum,sum2);
        // debug2(ncr(sum,m),ncr(sum2,m));
        ans += ncr(sum,m)%M - ncr(sum2,m)%M;
        ans += M;
        ans %= M;
    }
    ans = ans % M;
    cout << ans nl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    // // for(int i=0;i<100;i++)
    //     cout << fact[i] << " ";
    // cout nl;
    // for(int i=0;i<100;i++)
    //     cout << invfact[i] << " ";
    // cout nl;
	// cout << fact[4] sp invfact[2] nl;
    int t=1;
    cin >>t;

    while(t--)solve();

       
    return 0;
}