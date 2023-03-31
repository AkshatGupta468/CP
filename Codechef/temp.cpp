#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#define inf 1e6
struct  obj
{
    ll val;
    obj(ll tval){
        val=tval;
    }
    obj(){
        val=inf;
    }
};
class segmenttree
{
    obj nullval;
    obj combine(const obj &lval,const obj &rval)
    {
        return obj(min(lval.val,rval.val));
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
            arr[l]=combine(val,arr[l]);
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
    ll n,x;
    cin>>n>>x;

    vector<ll> a(n+1);
    vector<ll> pref(n+1,0);
    map<ll,ll> m;
    m[0]=1;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]-=x;
        pref[i]=pref[i-1]+a[i];
        m[pref[i]]=1;
    }
    ll index=1;
    // vector<obj> vs;
    for(auto &i:m){
        // vs.push_back(obj(i.second));
        i.second=index;
        index++;
    }
    // for(auto &i:m){
    //     cout<<i.first<<" "<<i.second<<nl;
    // }
    
    segmenttree S(index);
    vector<ll> ans;
    for(ll i=n;i>0;i--){
        // if(i<n && a[i]+a[i+1]<0){
        //     ans.push_back(i+1);
        //     S.treeupdate(m[pref[i]],obj(i));
        //     continue;
        // }
        obj val=S.findquery(1,m[pref[i-1]]-1);
        if(val.val==inf)val.val=n+1;
        ans.push_back(val.val);
        S.treeupdate(m[pref[i]],obj(i));
    }
    reverse(ans.begin(),ans.end());
    display(ans);
    cout<<nl;
}

int main()
{
    fast_io;

    ll t;
    cin>>t;
    while(t--)
        solve();

}
