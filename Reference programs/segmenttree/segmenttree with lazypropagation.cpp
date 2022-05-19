#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
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
void _dprint(vector<T> a){for(auto &i:a)cerr<<i<<" ";cerr nl;};
template<class T>
void _dprint(T a){cerr<<a<<"\n";}

struct  obj
{
    ll val;
    obj(ll tval){
        val=tval;
    }
    obj(){
        val=0;
    }
};
obj combine(const obj &lval,const obj &rval)
{
    return (lval.val+rval.val);
}
enum lazytype{
    LAZY_NONE,
    LAZY_INCREASE,
    LAZY_SETVAL
};
struct lazyobj{
   ll value=0;
   lazytype cmdtype=LAZY_NONE;
};
void fixindexing(int &a,int &b){
    --a;
    --b;
}
void fixindexing(int &k){
    k--;
}
class segmenttree
{
    public:
    obj nullval;
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
    int n;
    vector<obj> tree;
    vector<obj> arr;
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
    void lazytreedisplay(int v,int l,int r){
        // cerr<<v sp l sp r nl<< lazytree[v].value sp lazytree[v].type nl;
        if(l==r)return;
        int mid=(l+r)/2;
        lazytreedisplay(2*v,l,mid);
        lazytreedisplay(2*v+1,mid+1,r);
    }
    segmenttree(vector<obj> &tarr)
    {
        n=tarr.size();
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
    
    void rangeupdate(int a,int b,lazyobj update){
        fixindexing(a,b);
        if(a>b)return;
        recrangeupdate(0,n-1,a,b,1,update);
    }
    void recrangeupdate(int l,int r,int a,int b,int v,lazyobj update){
        resolve(v,l,r);
        //don't move this down 
        //node needs to be updated even if it is out of range because 
        // the ancestor nodes are dependent on this it can call a node
        // which is out of range of a-b

        //so ancestor wants all of its childs to be up-to-date as its value
        //is dependent on children
        if(r<a || l>b)
            return;
        // debug2(l,r);
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

    obj rangequery(int a,int b)
    {
        fixindexing(a,b);
        if(a>b) return nullval;
        return recrangequery(0,n-1,a,b,1);
    }
    obj pointquery(int k){
        fixindexing(k);
        return recrangequery(0,n-1,k,k,1);
    }
    obj recrangequery(int l,int r,int a,int b,int v)
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

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<obj> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].val;
    }
    segmenttree S(arr);
    while (q--)
    {
        int type;cin>>type;
        lazyobj x;
        int a,b;
        switch (type)
        {
        case 1:
            cin>>a>>b>>x.value;
            x.cmdtype=LAZY_INCREASE;
            S.rangeupdate(a,b,x);
            break;
        case 2:
            cin>>a>>b>>x.value;
            x.cmdtype=LAZY_SETVAL;
            S.rangeupdate(a,b,x);
            break;
        case 3:
            cin>>a>>b;
            cout<<S.rangequery(a,b).val nl;
            break;
        }
    }
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
        string path="../../";
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
        solve();
}

/*
notes
Memory Efficient implementation of Segment Trees
    let no.of nodes in subtree of v including v is size(v)=s
    let the no. of leaf nodes(length of segment) for which v holds is len(v)=n
    if n=1  s=1
    if n=2 
    =>s=3 => s=2*2-1 => 2*n -1
    let v1 and v2 are childs of node v
    if a node v1 holds n1 length of segment and v2 holds n2 length of segments
    the follwing process is true for n1<=2 and n2<=2
    size(v)=size(v1)+size(v2)+1
        => 2*n1-1 + 2*n2-1 +1
        =>2*(n1+ n2) -1
        =>2*n -1
    so now for n<=4 it is also true
    similarly for n<=8 it is also true 
    by induction it is true for all n
*/