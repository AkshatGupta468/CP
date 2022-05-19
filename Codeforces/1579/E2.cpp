#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
struct  obj
{
    int val;
    obj(int tval){
        val=tval;
    }
    obj(){
        val=0;
    }
};
class segmenttree
{
    obj nullval;
    obj combine(const obj &lval,const obj &rval)
    {
        return lval.val+rval.val;
        // return obj(max(lval.sngl,rval.sngl),max(lval.dobl,rval.dobl));
    }

    public:
    int n;
    vector<obj> tree;
    vector<obj> arr;
    segmenttree(int tn)
    {
        n=tn;
        tree.resize(4*n+1);
        arr.resize(n);
        build(1,0,n-1);
    }
    
    obj build(int index,int l,int r)
    {
        if(l==r)
        {
            tree[index]=arr[l];
            return tree[index];
        }
        int mid=(l+r)/2;
        tree[index]=combine(build(2*index,l,mid),build(2*index+1,mid+1,r));
        return tree[index];
    }

    void treeupdate(int k,obj val)
    {
        k--;
        recupdate(k,0,n-1,1,val);
        // treedisplay();cout<<nl;
    }
    obj recupdate(int k,int l,int r,int index,obj val)
    {
        if(k<l||r<k)
            return tree[index];
        if(l==r && l==k)
        {
            arr[l].val+=val.val;
            tree[index]=arr[l];
            return tree[index];
        }
        int mid=(l+r)/2;
        tree[index]=combine(recupdate(k,l,mid,2*index,val),recupdate(k,mid+1,r,2*index+1,val));
        return tree[index];
    }
    obj findquery(int a,int b)
    {
        a--;b--;
        if(a>b) return nullval;
        return rec(0,n-1,a,b,1);
    }
    obj rec(int l,int r,int &a,int &b,int index)
    {
        if(r<a || l>b)
        return nullval;
        if(a<=l && r<=b)
        return tree[index];
        int mid=(l+r)/2;
        return combine(rec(l,mid,a,b,2*index),rec(mid+1,r,a,b,2*index+1));
    }
};

void solve()
{
    int n;
    cin>>n;

    vector<pair<int,int>> a(n,{0,0});
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    vector<pair<int,int>> b(n);
    sort(a.begin(),a.end());
    b[0].first=1;
    b[0].second=a[0].second;
    for(int i=1;i<n;i++){
        b[i].second=a[i].second;
        if(a[i].first!=a[i-1].first)b[i].first=b[i-1].first+1;
        else b[i].first=b[i-1].first;
    }
    sort(b.begin(),b.end(),[](pair<int,int> &a,pair<int,int> &b)->bool{
        return a.second<b.second;
    });
    vector<obj> arr(n,obj(0));
    segmenttree S(n);
    ll ans=0;
    for(int i=0;i<n;i++){
        obj less=S.findquery(1,b[i].first-1);
        obj gret=S.findquery(b[i].first+1,n);
        ans+=min(less.val,gret.val);
        S.treeupdate(b[i].first,obj(1));
    }
    cout<<ans<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
