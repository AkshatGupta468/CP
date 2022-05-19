#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
class Fenwick
{
    vector<ll> tree;
    public:
    int n;
    vector<ll> arr;
    Fenwick(int tn,vector<ll> &tarr)
    {
        n=tn;
        arr.clear();
        arr.push_back(0);
        for(auto &i:tarr)
        {
            arr.push_back(i);
        }

        tree.resize(n+1);
        build();
    }

    void build()
    {
        tree[0]=0;
        for(int i=1;i<=n;i++)
        {
            treeupdateadd(i,arr[i]);
        }
    }
    void display()
    {
        for(auto i:tree)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    //Pass the index and the new value to be assigned
    void treeupdateadd(int x,ll val)
    {
        while(x<=n)
        {
            tree[x]+=val;
            x+=(x&(-x));
        }
        // display();
    }

    ll sumquery(int x)
    {
        if(x==0)
            return 0;
        return tree[x]+sumquery(x -(x&(-x)));
    }
};

int main()
{
    vector<ll> arr={4,3,2,5,1,6,7,8};
    Fenwick f(8,arr);
    cout<<f.sumquery(6)<<"\n";
    
    f.treeupdateadd(3,6);
  
    cout<<f.sumquery(6)<<"\n";
}
