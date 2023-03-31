vector<int> getzarray(string a) {
    int n = a.size();
    vector<int> z(n);
    int l = 1, r = 1;
    for (int i = 1;i < n;i++) {
        if (r - i >= 0)z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && a[i + z[i]] == a[z[i]])z[i]++;
        if (i + z[i] > r)l = i, r = i + z[i];
    }
    return z;
}

