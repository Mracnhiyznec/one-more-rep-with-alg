vector<ll> z_func(string &s){
    ll l, r;
    l = r = 0;
    ll len_str = s.size();
    vector<ll> z(len_str);
    z[0] = 0;
    for (int i = 1; i < len_str; i++){
        if (r >= i){
            z[i] = min(z[i - l], r - i + 1);
        }
        while (z[i] + i < s.size() && s[z[i] + i] == s[z[i]]){
            z[i]++;
        }
        if (z[i] + i - 1 > r){
            r = z[i] + i - 1;
            l = i;
        }
    }
    return z;
}
