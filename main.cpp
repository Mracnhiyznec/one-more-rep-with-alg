vector<ll> z_array(string &s){
    ll l = 0;
    ll r = 0;
    vector<ll> z(s.size());
    z[0] = 0;
    for (int i = 1; i < s.size(); i++){
        if (i <= r){
            if (z[i - l] < (r - i + 1)){
                z[i] = z[i - l];
            }
            else{
                z[i] = (r - i) + 1;
                while (z[i] + i < s.size() && (s[z[i]] == s[i + z[i]])){
                    z[i]++;
                }
            }
        }
        else{
            while (z[i] + i < s.size() && (s[z[i]] == s[i + z[i]])){
                z[i]++;
            }
        }
        if (z[i] + i - 1 > r){
            r = z[i] + i - 1;
            l = i;
        }
    }
    return z;
}
