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

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> maze(h);
    cin >> maze;
    // cout << maze << endl;
    deque<int> q;
    vector<int> dist(h * w + 26, 1e9);
    vector<vector<int>> super_vertex(26);
    rep(i, h)
    {
        rep(j, w)
        {
            if (maze[i][j] == 'S')
            {
                q.push_back({i * w + j});
                dist[i * w + j] = 0;
            }
            if ('a' <= maze[i][j] && maze[i][j] <= 'z')
            {
                super_vertex[maze[i][j] - 'a'].push_back({i * w + j});
            }
        }
    }
    // debug(q);
    // debug(super_vertex);
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (q.size())
    {
        int now = q.front();
        q.pop_front();
        if (now >= h * w)
        {
            for (int next : super_vertex[now - h * w])
            {
                if (dist[next] < 1e9)
                {
                    continue;
                }
                dist[next] = dist[now] + 1;
                q.push_back(next);
            }
            continue;
        }
        int cx = now / w;
        int cy = now % w;
        if (maze[cx][cy] == 'G')
        {
            cout << dist[now] << endl;
            return 0;
        }
        for (auto [dx, dy] : dxy)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            if (nx < 0 || h <= nx)
            {
                continue;
            }
            if (ny < 0 || w <= ny)
            {
                continue;
            }
            if (maze[nx][ny] == '#')
            {
                continue;
            }
            if (dist[nx * w + ny] < 1e9)
            {
                continue;
            }
            if ('a' <= maze[nx][ny] && maze[nx][ny] <= 'z')
            {
                int super = maze[nx][ny] - 'a';
                dist[nx * w + ny] = dist[cx * w + cy] + 1;
                dist[h * w + super] = dist[cx * w + cy] + 1;
                q.push_back({h * w + super});
            }
            else
            {
                dist[nx * w + ny] = dist[cx * w + cy] + 1;
                q.push_back({nx * w + ny});
            }
        }
    }
    cout << -1 << endl;
    // rep(i, h)
    // {
    //     rep(j, w)
    //     {
    //         int ans = dist[i * w + j];
    //         if (ans < 1e9)
    //         {
    //             cout << ans << ",";
    //         }
    //         else
    //         {
    //             cout << "-,";
    //         }
    //     }
    //     cout << endl;
    // }
}
