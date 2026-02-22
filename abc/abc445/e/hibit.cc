#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <stack>
#include <complex>
#include <array>
#include <cassert>
#include <random>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(A) A.begin(), A.end()
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << endl;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v)
{
    int n = v.size();
    int m = v[0].size();
    int p = v[0][0].size();
    rep(k, p)
    {
        os << "k = " << k << endl;
        rep(i, n)
        {
            rep(j, m)
            {
                os << v[i][j][k];
                if (j < m - 1)
                {
                    os << " ";
                }
                else
                {
                    os << endl;
                }
            }
        }
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

template <typename T, typename S>
ostream &operator<<(ostream &os, map<T, S> &mp)
{
    for (auto &[key, val] : mp)
    {
        os << key << ":" << val << " ";
    }
    cout << endl;
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, set<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, multiset<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, queue<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, deque<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop_front();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, stack<T> st)
{
    while (st.size())
    {
        os << st.top() << " ";
        st.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T> pq)
{
    while (pq.size())
    {
        os << pq.top() << " ";
        pq.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T, vector<T>, greater<T>> mpq)
{
    while (mpq.size())
    {
        os << mpq.top() << " ";
        mpq.pop();
    }
    return os;
}

vector<ll> first_divisor;

void set_first_divisors(ll n) {
  first_divisor.resize(n + 1);
  for (ll i = 2; i < n + 1; i++) first_divisor[i] = i;
  for (ll i = 2; i * i < n + 1; i++) {
    if (first_divisor[i] == i) {
      for (ll j = i * i; j < n + 1; j += i) {
        if (first_divisor[j] == j) first_divisor[j] = i;
      }
    }
  }
}

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> ans;
  while (n >= 2) {
    ll p = first_divisor[n];
    ll r = 0;
    while (n >= 2 and first_divisor[n] == p) {
      n /= p;
      r++;
    }
    ans.emplace_back(p, r);
  }
  return ans;
}


vector<pair<ll, ll>> old_prime_factorize(ll n)
{
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll ex = 0;
            while (n % i == 0)
            {
                ex++;
                n /= i;
            }
            ans.push_back({i, ex});
        }
    }
    if (n != 1)
    {
        ans.push_back({n, 1});
    }
    return ans;
}
#include <atcoder/modint>
using namespace atcoder;
using mint=modint998244353;
ostream &operator<<(ostream &os, mint &i)
{
    os << i.val();
    return os;
}

ostream &operator<<(ostream &os, const vector<mint> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i].val() << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}
vector<ll> solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    map<ll,vector<ll>> best_for_prime;
    rep(i,n){
        for(auto [key,val]:prime_factorize(a[i])){
            best_for_prime[key].push_back(val);
        }
    }
    mint total = 1;
    // debug(best_for_prime);
    for(auto& [key,val]:best_for_prime){
        sort(all(val),greater());
        while(val.size()>2){
            val.pop_back();
        }
        total *= mint(key).pow(val[0]);
    }
    // debug(total);
    // debug(best_for_prime);
    vector<ll> ans(n);
    rep(i,n){
        mint tmp = total;
        for(auto [key,val]:prime_factorize(a[i])){
            while(best_for_prime[key].size()<2){
                best_for_prime[key].push_back(0);
            }
            if(val == best_for_prime[key][0]){
                tmp /= mint(key).pow(best_for_prime[key][0]-best_for_prime[key][1]);
            }
        }
        ans[i] = tmp.val();
    }
    return ans;
}
int main(){
    set_first_divisors((ll)1e7);
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}
