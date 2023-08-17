//Fenwick Tree(Binary Indexed Tree)
//Make a structure to handle Dynamic Range queries
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
/*
LSB-Least Significant Bit
it is the rightmost set Bit in the Binary representation of a number.
    
One's complement:
    it is the value obtained by inverting all the zeros of binary representation of the number

Two's complement:
    =One's complement + 1

How LSB can be found?
    LSB is the common set bit among the number and it's Two's complement.

How to find Two's complement?
    Negative of a number is stored as Two's complement the number in computers.

Hence LSB= num & (-num)
*/

class Fenwick
{ 
    //ith element of the tree stores the sum of last LSB(i) indexes(including ith index)
    //where LSB(k) represents the Decimal equivalent of k
    vector<ll> tree;
    public:
    int n;
    vector<ll> arr;
    //constructor to recieve size of tree and the vector
    Fenwick(vector<ll> &tarr)
    {
        n=tarr.size();
        arr.clear();

        arr.push_back(0); //Push zero to front of array to make it one based
        for(auto &i:tarr)
        {
            arr.push_back(i);
        }

        //using one based indexing for tree
        tree.resize(n+1);
        build();
    }

    //Build function to add the array values to the tree
    //Adding elements using update query for each index
    void build()
    {
        tree[0]=0;
        for(int i=1;i<=n;i++)
        {
            treeupdate_add(i,arr[i]);
        }
    }
    
    //Function to add val to xth index of arr
    //Pass the index and the value to be added
    //Time-complexity => O(log(n))
    void treeupdate_add(int x,ll val)
    {
        while(x<=n)
        {
            tree[x]+=val;
            x+=(x&(-x));    //Next update occurs after LSB(x) indexes
        }
    }

    //sum_qurey gives the sum of first x indexes
    //Time-Complexity => O(log(n))
    ll sum_query(int x) 
    {
        if(x==0)
            return 0;
        //Since tree[x] stores the sum of last LSB indexes
        //we make a recursive call of sum query of first x-LSB(x) indexes.
        return tree[x]+sum_query(x -(x&(-x)));
    }

    //Sum of range [l,r] can be calculated using sum_query(r)-sum_query(l-1)
    ll range_sum(int l,int r)
    {
        return sum_query(r)-sum_query(l-1);
    }
};

//Driver code
int main()
{

    vector<ll> arr={4,3,2,5,1,6,7,8};
    Fenwick f(arr); //passing the array in constructor
    //sum of range [3,6]
    cout<<f.range_sum(3,6)<<"\n";
    
    f.treeupdate_add(4,6);
  
    cout<<f.range_sum(3,6)<<"\n";

    // int n,q;
    // cin>>n>>q;
    // vector<ll> arr(n);
    // for(auto &i:arr) cin>>i;
    // Fenwick f(arr);
    // for(int i=0;i<q;i++)
    // {
    //     int w;
    //     cin>>w;
    //     if(w==1)
    //     {
    //         int k,u;
    //         cin>>k>>u;
    //         f.treeupdate_add(k,u-arr[k-1]);
    //         arr[k-1]=u;
    //     }
    //     else
    //     {
    //         int l,r;
    //         cin>>l>>r;
    //         cout<<f.range_sum(l,r)<<"\n";
    //     }
    // }
}
