#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
#define debug(x) std::cerr << __FUNCTION__ << ":" << __LINE__ << " " << #x << " = " << x << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;
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
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    vector<ll> z;
    z = z_func(s);
    for (auto c: z) cout << c << " ";
    return 0;
}
