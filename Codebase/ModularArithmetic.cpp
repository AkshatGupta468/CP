long long binaryMultiply(long long, long long, long long);

int binaryExp(int a, int b, int M)
{
    // base a
    //power b
    //modular M
    //(a^b)%M

    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1ll * a) % M;
        }
        a = (a * 1ll * a) % M;
        b >>= 1;
    }
    return ans;
}

long long binaryMultiply(long long a, long long b, long long M)
{
    long long ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

long long binaryExp_Big(long long a, long long b, long long M)
{
    //take b=b%(M-1); only valid if M is primes//ETF //Euler's theorem
    //take a=a%M

    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = binaryMultiply(ans, a, M);
        }
        a = binaryMultiply(a, a, M);
        b >>= 1;
    }
    return ans;
}

int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i - 1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n / p) % 2)
            res = p - res;
        res = res * f[n % p] % p;
        n /= p;
    }
    return res;
}


int multiplicity_factorial(int n, int p) {
    int count = 0;
    do {
        n /= p;
        count += n;
    } while (n);
    return count;
}