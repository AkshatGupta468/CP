//Modular exponentation and Modular Multiplication
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

/*
    Modular Exponentiation is used to calculate 
    the value of (a^b)mod m
    
    A number can be written in its binary form as
    b=p[0]*2^0 + p[1]*2^1 + p[2]*2^2 .....
    where p is the binary representation of b.(p[i] is ith bit from left)
    p[i] can be 0 or 1
    so (a^b)=(a^(p[0]*2^0))*(a^(p[1]*2^1))*(a^(p[2]*2^2))*....
    (a^b)%M=(   
                (   
                    ((a^(2^0))^p[0])%M 
                    *
                    ((a^(2^1))^p[1])%M
                )%M
                *((a^(2^2))^p[2])%M
            )%M*....

    This expression is implemented to calculate the value of (a^b) mod M
*/
/*
    Modular Multiplication is used to calculate 
    value of (a*b)%M.
    
    When a and b are of order 10^9 this can be calculated just by (a*1ll*b)%M
    but when a*b exceeds the LONG_LONG_MAX limit then we have to use Modular multiplication to calculate (a*b)%M
    
    (a*b)=(a*(p[0]*2^0))+(a*(p[1]*2^1))+(a*(p[2]*2^2))+....
    
    (a*b)%M=(   
                (   
                    ((a*(2^0))*p[0])%M 
                    +
                    ((a*(2^1))*p[1])%M
                )%M
                +((a*(2^2))*p[2])%M
            )%M*....

    This expression is implemented to calculate the value of (a*b) mod M

*/

//Modular Exponentiation function such that 0<=a,b,M<=10^9
//Time-Complexity => O(log(b))
int ModularExp(int a,int b,int M)
{
    // base a
    //power b
    //modular M
    //(a^b)%M

    int ans=1;
    while(b>0)
    {
        //Each time we check the rightmost bit of b and then we right-shift it.
        if(b&1)
        {
            ans=(ans*1ll*a)%M;  
        }
        //In the exxpression it can be seen that value of a gets squared in each step.
        a=(a*1ll*a)%M;
        b>>=1;
    }
    return ans;
}

//Modular Multiplication such that 0<=a,b,M<=10^18
//Time-Complexity O(log(b))
long long ModularMultiply_Big(long long a,long long b,long long M)
{
    // (a*b) mod M
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

//Modular Exponentiation such that 0<=a,b,M<=10^18
//Time-Complexity => O(log(b)*log(M))
long long ModularExp_Big(long long a,long long b,long long M)
{
    long long ans=1;
    while(b>0)
    {
        if(b&1)
        {
            //Direct multiplication cannot be used as (ans*a) can exceed LONG_LONG_MAX
            ans=ModularMultiply_Big(ans,a,M);      
        }
        //Direct multiplication cannot be used as (a*a) can exceed LONG_LONG_MAX
        a=ModularMultiply_Big(a,a,M);
        b>>=1;
    }
    return ans;
}

//Driver Code
int main()
{
    cout<<ModularMultiply_Big(12233234124ll,1234122324ll,MOD);
    cout<<ModularExp_Big(1233444343434ll,123434343434ll,234234224)<<"\n";
    cout<<ModularExp(1234,1234,2234224)<<"\n";
    
}
