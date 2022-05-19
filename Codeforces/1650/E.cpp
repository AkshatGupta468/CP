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
int n,d;
pair<int,vector<int>> getminpos(vector<int> &a){
    vector<int> minpos;int minval=2e9; 
    for(int i=1;i<a.size();i++){
        if(a[i]-a[i-1]<minval){
            minpos.clear();
            minpos.push_back(i);
            minval=a[i]-a[i-1];
        }
        else if(a[i]-a[i-1]==minval){
            minpos.push_back(i);
        }
    }
    return {minval,minpos};
}
int fun(int x,vector<int> &t){
    vector<int> a=t;
    int ans=0;
    int posx=a[x];
    a.erase(a.begin()+x);
    if(a[n]!=d){
        a.push_back(d);
        pair<int,vector<int>>  feedback=getminpos(a);
        a.pop_back();
        ans=feedback.first;
    }
    int maxlen=0,maxlenpos=1;
    for(int i=1;i<a.size();i++){
        if(a[i]-a[i-1]>maxlen){
            maxlen=a[i]-a[i-1];
            maxlenpos=i;
        }
    }
    a.insert(a.begin()+maxlenpos,{maxlen/2+a[maxlenpos-1]});
    ans=max(ans,getminpos(a).first);
    return ans;
}
int solve()
{
    cin>>n>>d;
    vector<int> a(n+1);
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    pair<int,vector<int>> feedback=getminpos(a);
    if(feedback.second.size()>2) return feedback.first;
    if(feedback.second.size()==2){
        if(feedback.second[0]+1==feedback.second[1])return fun(feedback.second[0],a);
        else return feedback.first;
    }
    else if(feedback.second[0]==1)return fun(1,a);
    else return max(fun(feedback.second[0]-1,a),fun(feedback.second[0],a));
}

int main()
{
        fast_io;
     #ifdef __linux__
        string path="/mnt/3C401CB3401C75BC/CP/";
     #elif _WIN32
        string path="D:/CP/";
     #endif
     #ifndef ONLINE_JUDGE
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        cout<<solve() -1 nl;
}
