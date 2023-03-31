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
void _dprint(vector<T> a){display(a)};
template<class T>
void _dprint(T a){cerr<<a<<"\n";}
struct  obj
{
    int val;
    obj(int tval){
        val=tval;
    }
    obj(){
        val=INT_MAX;
    }
};
class segmenttree
{
    obj nullval;
    obj combine(const obj &lval,const obj &rval)
    {
        return max(lval.val,rval.val);
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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    display(a);
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/CP/input.txt", "r", stdin);
        freopen("D:/CP/output.txt", "w", stdout);
        freopen("D:/CP/error.txt","w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
