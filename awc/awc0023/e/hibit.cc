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
struct S
{
    /* data */
    ll box_cnt;
    ll last_weight;
};

ostream& operator<<(ostream& os, const S& s) {
    os << "{" << s.box_cnt << "," << s.last_weight << "}";
    return os;
}

bool operator<(const S& a, const S& b) {
    if (a.box_cnt != b.box_cnt){
        return a.box_cnt < b.box_cnt;
    }
    return a.last_weight < b.last_weight;
}


int main(){
    #define int ll
    int n,c;
    cin >> n >> c;
    int LIM = 2e9;
    vector<S> dp(1<<n,{LIM,LIM});
    dp[0] = {1,0};
    // cout << dp << endl;
    vector<int> w(n);
    cin >> w;
    rep(i,1<<n){
        auto [now_cnt,last_weight] = dp[i];
        // rep(j,n){
        //     if(!i>>j&1){
        //         continue;
        //     }
            rep(next_j,n){
                if(i>>next_j&1){
                    continue;
                }
                int next_i = i^(1<<next_j);
                auto chmin=[](auto& a, const auto& b){
                    if(b<a){
                        a=b;
                        return true;
                    }
                    return false;
                };
                if(last_weight+w[next_j] > c){
                    chmin(dp[next_i],S{now_cnt+1,w[next_j]});
                }else{
                    chmin(dp[next_i],S{now_cnt,last_weight+w[next_j]});
                }
            }
        // }
    }
    cout << dp[(1<<n)-1].box_cnt << endl;
}
