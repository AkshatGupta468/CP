#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
long long binaryMultiply(long long ,long long ,long long);

int binaryExp(int a,int b,int M)
{
    // base a
    //power b
    //modular M
    //(a^b)%M

    int ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans*1ll*a)%M;
        }
        a=(a*1ll*a)%M;
        b>>=1;
    }
    return ans;
}

long long binaryMultiply(long long a,long long b,long long M)
{
    long long ans=0;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans + a)%M;
        }
        a=(a + a)%M;
        b>>=1;
    }
    return ans;
}

long long binaryExp_Big(long long a,long long b,long long M)
{
    //take b=b%(M-1); only valid if M is primes//ETF //Euler's theorem
    //take a=a%M

    ll ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=binaryMultiply(ans,a,M);
        }
        a=binaryMultiply(a,a,M);
        b>>=1;
    }
    return ans;
}

int main()
{
    cout<<binaryMultiply(1234124,1234124,MOD);
    cout<<binaryExp_Big(1234,1234,2234224)<<"\n";
    cout<<binaryExp(1234,1234,2234224)<<"\n";
}
