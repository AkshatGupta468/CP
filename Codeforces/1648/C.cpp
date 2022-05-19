#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define display(a) for(auto i:a)cerr<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug2(n1,n2) cerr << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n); 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a){display(a)};
template<class T>
void _dprint(T a){cerr<<a<<"\n";}
vector<ll> fac;
enum lazytype{
    LAZY_NONE,
    LAZY_INCREASE,
    LAZY_SETVAL
};
struct  node
{
    ll val;
    node(ll tval){
        val=tval;
    }
    node(){
        val=0;
    }
};
node combine(const node &lval,const node &rval)
{
    return (lval.val+rval.val);
}
struct lazyobj{
   ll value=0;
   lazytype cmdtype=LAZY_NONE;
};

class segmenttree
{
    public:
    node nullval;
    bool inputisonebased;
    void propagatecommand(lazyobj &updatethis,const lazyobj &refrlazy){
        switch (refrlazy.cmdtype)
        {
        case LAZY_NONE:
            break;
        case LAZY_SETVAL:
            updatethis.value=refrlazy.value;
            updatethis.cmdtype=LAZY_SETVAL;
            break;
        case LAZY_INCREASE:
            updatethis.value+=refrlazy.value;
            if(updatethis.cmdtype==LAZY_NONE)
                updatethis.cmdtype=refrlazy.cmdtype;
            break;
        }
    }
    void fixindexing(int &a,int &b){
        a-=inputisonebased;
        b-=inputisonebased;
    }
    void fixindexing(int &k){
        k-=inputisonebased;
    }
    int n;
    vector<node> tree;
    vector<node> arr;
    vector<lazyobj> lazytree;
    void resolve(int v,int l,int r){
        switch(lazytree[v].cmdtype){
            case LAZY_NONE:
                break;
            case LAZY_INCREASE:
                tree[v].val+=lazytree[v].value*(r-l+1);
                break;
            case LAZY_SETVAL:
                tree[v].val=lazytree[v].value*(r-l+1);
                break;
        }
        if(l==r){
            arr[l].val=tree[v].val;
        }
        else{
            propagatecommand(lazytree[2*v],lazytree[v]);
            propagatecommand(lazytree[2*v+1],lazytree[v]);
        } 
        lazytree[v].value=0;
        lazytree[v].cmdtype=LAZY_NONE;
    }
    
    segmenttree(vector<node> &tarr,bool _inputisonebased)
    {
        n=tarr.size();
        inputisonebased=_inputisonebased;
        tree.resize(4*n+1);
        lazytree.resize(4*n+1);
        arr=tarr;
        build(1,0,n-1);
    }
    void build(int v,int l,int r)
    {
        if(l==r)
        {
            tree[v]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*v,l,mid);
        build(2*v+1,mid+1,r);
        tree[v]=combine(tree[2*v],tree[2*v+1]);
    }
    void pointupdate(int k,lazyobj update){
        fixindexing(k);
        recrangeupdate(0,n-1,k,k,1,update);
    }
    void rangeupdate(int a,int b,lazyobj update){
        fixindexing(a,b);
        if(a>b)return;
        recrangeupdate(0,n-1,a,b,1,update);
    }
    void recrangeupdate(int l,int r,int a,int b,int v,lazyobj update){
        resolve(v,l,r);
        if(r<a || l>b) return;
        if(a<=l && r<=b){
            propagatecommand(lazytree[v],update);
            resolve(v,l,r);
            return;
        }
        int mid=(l+r)/2;
        recrangeupdate(l,mid,a,b,2*v,update);
        recrangeupdate(mid+1,r,a,b,2*v+1,update);
        tree[v]=combine(tree[2*v],tree[2*v+1]);
    }

    node rangequery(int a,int b)
    {
        fixindexing(a,b);
        if(a>b) return nullval;
        return recrangequery(0,n-1,a,b,1);
    }
    node pointquery(int k){
        fixindexing(k);
        return recrangequery(0,n-1,k,k,1);
    }
    node recrangequery(int l,int r,int a,int b,int v)
    {
        resolve(v,l,r);
        if(r<a || l>b)
            return nullval;
        if(a<=l && r<=b)
            return tree[v];
        int mid=(l+r)/2;
        return combine(recrangequery(l,mid,a,b,2*v),recrangequery(mid+1,r,a,b,2*v+1));
    }
};

int binaryExp(int a,int b)
{
    // base a
    //power b
    //modular M
    //(a^b)%M
    int M=MOD;
    int ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans*1ll*a)%M;
        }
        a=(a*1ll*a)%M;
        b>>=1;
    }
    return ans;
}
int inv(ll x){
    return binaryExp(x,MOD-2);
}
void solve()
{
    ll n,m;cin>>n>>m;
    vector<int> s(n),t(m);
    vector<node> cnt(2e5+1,0);
    for(auto &i:s){
        cin>>i;
        cnt[i].val++;
    }
    for(auto &i:t)cin>>i;
    ll perm=fac[n];
    for(ll i=1;i<cnt.size();i++){
        perm=(perm*inv(fac[cnt[i].val]))%MOD;
    }
    ll ans=0;
    segmenttree S(cnt,false);
    bool ends=true;
    for(int i=0;i<min(n,m);i++){
        ans=(ans+S.rangequery(1,t[i]-1).val*inv(n-i)%MOD*perm%MOD)%MOD;
        if(S.pointquery(t[i]).val==0){
            ends=false;
            break;
        }
        perm=(perm*inv(n-i)%MOD)*S.pointquery(t[i]).val%MOD;
        S.pointupdate(t[i],lazyobj({-1,LAZY_INCREASE}));
    }
    cout<< (ans +ends*(n<m))%MOD nl;
}

int main()
{
        // fast_io;
    #ifndef ONLINE_JUDGE
    // string path="/mnt/3C401CB3401C75BC/CP/";
    string path="D:/CP/";
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    fac.push_back(1);
    for(ll i=1;i<=2e5;i++)fac.push_back(fac[i-1]*i%MOD);
        solve();
}
