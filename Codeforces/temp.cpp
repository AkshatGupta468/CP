#include<bits/stdc++.h>
#include<random>
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

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
        // freopen("D:/CP/input.txt", "r", stdin);
        freopen("D:/CP/input.txt", "w", stdout);
        freopen("D:/CP/error.txt","w",stderr);
    #endif
    cout<<1 nl;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    int MINN=1;
    int MAXN=1e7;
    uniform_int_distribution<int> getnum(MINN,MAXN);
    int n=1e5;
    cout<< n nl;
    for(int i=0;i<n;i++){
        cout<<getnum(generator)<<" ";
    }
    cout nl;
    
}
