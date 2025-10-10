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
auto chmax = [](auto &a, const auto &b) {
    if(a<b){
        a=b;
        return true;
    }
    return false;
};
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w));
    cin >> a;
    vector<ll> p(h+w-1);
    cin >> p;
    ll ng = -1;
    ll ok = 1e18;
    while(abs(ng-ok)>1){
        ll mid = ng+ok;
        mid /= 2;
        // debug(mid);
        vector<vector<ll>> dp(h,vector<ll>(w,-1e18));
        dp[0][0] = mid+a[0][0]-p[0];
        rep(i,h){
            rep(j,w){
                if(dp[i][j]<0){
                    continue;
                }
                if(i==h-1 && j==w-1){
                    continue;
                }
                int step = i+j+1;
                ll cost = p[step];
                if(i+1<h){
                    if(dp[i][j]+a[i+1][j]-cost>=0){
                        chmax(dp[i+1][j],dp[i][j]+a[i+1][j]-cost);
                    }
                }
                if(j+1<w){
                    if(dp[i][j]+a[i][j+1]-cost>=0){
                        chmax(dp[i][j+1],dp[i][j]+a[i][j+1]-cost);
                    }
                }
            }
        }
        // cout << dp << endl;
        if(dp[h-1][w-1]>-1e18){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
}
