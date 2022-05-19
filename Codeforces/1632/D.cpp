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
        return __gcd(lval.val,rval.val);
        // return obj(max(lval.sngl,rval.sngl),max(lval.dobl,rval.dobl));
    }

    public:
    int n;
    vector<obj> tree;
    vector<obj> arr;
    segmenttree(int tn,vector<obj> &tarr)
    {
        n=tn;
        tree.resize(4*n+1);
        arr=tarr;
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
            tree[index]=val;
            arr[l]=val;
            return val;
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

    vector<obj> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].val;
    }
    int l=1,r=1;
    segmenttree S(n,a);
    vector<int> ans(n+1);
    while(r<=n){
        obj v=S.findquery(l,r);
        int val=v.val;
        if(val>r-l+1){
            r++;
        }
        else if(val==r-l+1){
            ans[r]=1;
            r++;
            l=r;
        }
        else {
            l++;
        }
    }
    for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<" ";
    }
    cout<<nl;
}

int main()
{
    fast_io;
        solve();

}
