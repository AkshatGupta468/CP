vector<int> sieve(int size)
{
    vector<int> fac(size);
    int n = fac.size();
    for (int i = 0;i < n;i++) fac[i] = i;
    for (int i = 2;i * i <= n;i++)
    {
        for (int j = i * i;fac[i] == i && j < n;j += i)
            fac[j] = min(i, fac[j]);
    }
    return fac;
}