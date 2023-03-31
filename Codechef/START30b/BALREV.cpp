#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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
enum lazytype{
    LAZY_NONE,
    LAZY_INCREASE,
    LAZY_SETVAL
};
struct  node
{
    ll val,pos;
    node(ll tval,ll pos){
        val=tval;
    }
    node(){
        val=LLONG_MAX;
        pos=0;
    }
};
node combine(const node &lval,const node &rval)
{
    if(lval.val<rval.val)return lval;
    else return rval;
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

int fun(int l,int r, segmenttree &S,int n){
    return 
}
void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    ll minm=LLONG_MAX;
    for(ll i=0;i<n;i++){
        a[i]-=b[i];
        minm=min(a[i],minm);
    }
    vector<node> v(n);
    for(ll i=0;i<n;i++){
        a[i]+=minm;
        v[i].val=a[i];
        v[i].pos=i;
    }
    segmenttree S(v,false);
    ll ans=fun(0,n,S,n);
    if(ans>v[n-1].val)cout<<"-1\n";
    else cout<<ans nl;
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
    string path="/mnt/3C401CB3401C75BC/CP/";
    // string path="D:/CP/";
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
