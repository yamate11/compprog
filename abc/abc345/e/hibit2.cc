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
#include <unordered_map>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
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

// Define the hash function
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // If the hash function for `std::pair` is not provided by the standard library,
        // a good practice is to combine the two hashes like this.
        return h1 ^ h2;
    }
};

// Define the equality function
struct pair_equal {
    template <class T1, class T2>
    bool operator () (const std::pair<T1,T2> &p1, const std::pair<T1,T2> &p2) const {
        return p1.first == p2.first && p1.second == p2.second;
    }
};

using S = pair<ll,ll>;
using mymap = unordered_map<S, ll, pair_hash, pair_equal>;

int main(){
    int n,k;
    cin >> n >> k;
    mymap dp;
    dp[{0,0}] = 0;
    // debug(dp);
    mymap ep;
    mymap mp;
    rep(i,n){
        ll c,v;
        cin >> c >> v;
        ep.clear();
        mp.clear();
        for(auto& [key,val] : dp){
            auto& [cnt,last] = key;
            auto chmax = [](auto &a, auto b)
            { a = max(a, b); };
            if(cnt+1 <= k){
                // chmax(ep[{cnt+1,last}],val);
                chmax(mp[{cnt+1,last}],val);
            }
            if(last != c){
                // chmax(ep[{cnt,c}],val+v);
                chmax(mp[{cnt,c}],val+v);
            }
        }
        // cerr << "ssize(mp) " << ssize(mp) << endl;
        // debug(mp);
        vector<vector<pair<ll,ll>>> vp(k+1);
        for(auto& [key,val] : mp){
            auto& [cnt,last] = key;
            vp[cnt].push_back({val,last});
        }
        // cout << vp << endl;
        rep(j,k+1){
            sort(all(vp[j]));
            reverse(all(vp[j]));
            while(vp[j].size()>2){
                vp[j].pop_back();
            }
            for(auto& [val,last] : vp[j]){
                ep[{j,last}] = val;
            }
        }
        dp = move(ep);
        // for(auto [key,val] : dp){
        //     cout << key << ":" << val << " ";
        // }
        // cout << endl;
    }
    ll ans = -1;
    for(auto& [key,val] : dp){
        auto& [cnt,last] = key;
        if(cnt != k){
            continue;
        }
        auto chmax = [](auto &a, auto b)
        { a = max(a, b); };
        chmax(ans,val);
    }
    cout << ans << endl;
}
