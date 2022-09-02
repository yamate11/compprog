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

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<set<int>> vertical(h), horizontal(w);
    rep(i, h)
    {
        vertical[i].insert(-1);
    }
    rep(j, w)
    {
        horizontal[j].insert(-1);
    }
    vector<string> maze(h);
    cin >> maze;
    rep(i, h)
    {
        rep(j, w)
        {
            if (maze[i][j] == '#')
            {
              vertical[i].insert(vertical[i].end(), j);
              horizontal[j].insert(horizontal[j].end(), i);
            }
        }
    }
    rep(i, h)
    {
      vertical[i].insert(vertical[i].end(), w);
    }
    rep(j, w)
    {
      horizontal[j].insert(horizontal[j].end(), h);
    }
    int ans = 0;
    vector<int> h_cache(w, -1);
    rep(i, h)
    {
        int w_cache = -1;
        rep(j, w)
        {
            if (maze[i][j] == '#')
            {
                h_cache[j] = w_cache = -1;
                continue;
            }
            int h_light = h_cache[j];
            if (h_light < 0)
            {
                auto it_h = horizontal[j].upper_bound(i);
                h_cache[j] = h_light = *it_h - *prev(it_h) - 1;
            }
            int w_light = w_cache;
            if (w_light < 0)
            {
                auto it_w = vertical[i].upper_bound(j);
                w_cache = w_light = *it_w - *prev(it_w) - 1;
            }  
            // debug(h_light);
            // debug(w_light);
            auto chmax = [](auto &a, auto b)
            { a = max(a, b); };
            chmax(ans, h_light + w_light - 1);
        }
    }
    cout << ans << endl;
}
